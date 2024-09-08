#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <future>
#include <atomic>

class ThreadPool {
public:
  ThreadPool(size_t threadCount) : stop(false) {
    for (size_t i = 0; i < threadCount; ++i) {
      workers.emplace_back([this] {
        while (true) {
          std::function<void()> task;

          {   // 任务队列保护锁
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this] {
              return stop || !tasks.empty();
            });
            if (stop && tasks.empty()) return;
            task = std::move(tasks.front());
            tasks.pop();
          }

          // 执行任务
          task();
        }
      });
    }
  }

  template<class F, class... Args>
  auto enqueue(F&& f, Args&&... args) 
  -> std::future<typename std::result_of<F(Args...)>::type> {
      
    using returnType = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared<std::packaged_task<returnType()>>(
      std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    std::future<returnType> result = task->get_future();

    {
      std::unique_lock<std::mutex> lock(queueMutex);
      if (stop) throw std::runtime_error("enqueue on stopped ThreadPool");
      tasks.emplace([task]() { (*task)(); });
    }

    condition.notify_one();
    return result;
  }

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(queueMutex);
      stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers) {
      worker.join();
    }
  }

private:
  std::vector<std::thread> workers;
  std::queue<std::function<void()>> tasks;

  std::mutex queueMutex;
  std::condition_variable condition;
  std::atomic<bool> stop;
};
