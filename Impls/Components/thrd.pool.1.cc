#include <functional>

#include <mutex>
#include <condition_variable>
#include <thread>

#include <vector>
#include <queue>

class ThreadPool {
private:
  void ThreadLoop();

public:
  void Start();
  void QueueJob(const std::function<void()>& job);
  bool Busy();
  void Stop();

private:
  //! Tells threads to stop looking for jobs
  bool _should_terminate = false; 
  //! Prevents data races to the job queue
  std::mutex _mutex;
  //! Allows threads to wait on new jobs or termination 
  std::condition_variable _mutex_condition; 
  std::vector<std::thread> _threads;
  std::queue<std::function<void()>> _jobs;
};

//! @brief 
//! The infinite loop function. This is a while (true) loop waiting for the 
//! task queue to open up.
void ThreadPool::ThreadLoop() {
  while (true) {
    std::function<void()> job;
    {
      std::unique_lock<std::mutex> lock(_mutex);
      
      _mutex_condition.wait(lock, [this] {
        return !_jobs.empty() || _should_terminate;
      });
      
      if (_should_terminate)
        return;
      
      job = _jobs.front();
      _jobs.pop();
    }
    job();
  }
}

//! @brief 
//! Each thread should be running its own infinite loop, constantly waiting 
//! for new tasks to grab and run.
void ThreadPool::Start() {
  const uint32_t num_threads = std::thread::hardware_concurrency();
  for (uint32_t i = 0; i < num_threads; ++i) {
    _threads.emplace_back(std::thread(&ThreadPool::ThreadLoop, this));
  }
}

//! @brief 
//! Add a new job to the pool; use a lock so that there isn't a data race.
void ThreadPool::QueueJob(const std::function<void()>& job) {
  {
    std::unique_lock<std::mutex> lock(_mutex);
    _jobs.push(job);
  }
  _mutex_condition.notify_one();
}

//! @brief 
//! The busy() function can be used in a while loop, such that the main 
//! thread can wait the threadpool to complete all the tasks before calling 
//! the threadpool destructor.
bool ThreadPool::Busy() {
  bool pool_busy;
  {
    std::unique_lock<std::mutex> lock(_mutex);
    pool_busy = !_jobs.empty();
  }
  return pool_busy;
}

//! @brief 
//! Stop the pool.
void ThreadPool::Stop() {
  {
    std::unique_lock<std::mutex> lock(_mutex);
    _should_terminate = true;
  }
  _mutex_condition.notify_all();
  for (auto& active_thrd : _threads) {
    active_thrd.join();
  }
  _threads.clear();
}
