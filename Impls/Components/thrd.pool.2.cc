#include <iostream>
#include <functional>
#include <future>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <utility>


class ThreadPool {
private:
  void ThreadLoop();

public:
  template <typename Func, typename... Args>
  auto QueueJob(Func&& func, Args&&... args)
   -> std::future<typename std::invoke_result<Func, Args...>::type>;
  
  void Start();
  bool Busy();
  void Stop();

private:
  bool _should_terminate = false; 
  std::mutex _mutex;
  std::condition_variable _mutex_condition; 
  std::vector<std::thread> _threads;
  std::queue<std::function<void()>> _jobs;
};

///////////////////////////////////////////////////////////////////////

void ThreadPool::ThreadLoop() {
  while (true) {
    std::function<void()> job;
    {
      std::unique_lock<std::mutex> lock(_mutex);
      _mutex_condition.wait(lock, [this] {
        return !this->_jobs.empty() || this->_should_terminate;
      });

      if (this->_should_terminate)
        return;
      
      job = _jobs.front(); _jobs.pop();
    }
    job();
  }
}

void ThreadPool::Start() {
  const uint32_t num_threads = std::thread::hardware_concurrency();
  for (int i = 0; i < num_threads; ++i) {
    //❗这里指定类名与传入 this 并不是多余的，这是线程的静态工作特性
    // 也就是说线程本身并不归属于任何一个类实例，所以必须传入当前 this
    _threads.push_back(std::thread(&ThreadPool::ThreadLoop, this));
  }
}

bool ThreadPool::Busy() {
  std::unique_lock<std::mutex> lock(_mutex);
  return !this->_jobs.empty();
}

void ThreadPool::Stop() {
  {
    std::unique_lock<std::mutex> lock(_mutex);
    _should_terminate = true;
  }
  _mutex_condition.notify_all();
  for (auto& thrd : _threads) {
    thrd.join();
  }
  _threads.clear();
}

template <typename Func, typename... Args>
auto ThreadPool::QueueJob(Func&& func, Args&&... args)
 -> std::future<typename std::invoke_result<Func, Args...>::type> 
{
  using return_type = typename std::invoke_result<Func, Args...>::type;

  //❗这里使用智能指针是因为 package_task 需要在堆上传递给线程，
  // 因为 package_task 绑定了 future 无法触发传参拷贝。
  auto task = std::make_shared<std::packaged_task<return_type()>>(
    std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
  );

  std::future<return_type> res = task->get_future();

  {
    std::unique_lock<std::mutex> lock(_mutex);
    _jobs.emplace([task] { (*task)(); });
  }

  _mutex_condition.notify_one();
  return res;
}
