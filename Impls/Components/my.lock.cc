
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>

class Spinlock {
private:
  // 原子类型，只能设置和清除
  std::atomic_flag lock_flag = ATOMIC_FLAG_INIT;

public:
  void lock() {
    while (lock_flag.test_and_set(std::memory_order_acquire));
  }

  void unlock() {
    lock_flag.clear(std::memory_order_release);
  }
};


class BlockingLock {
private:
  std::atomic<bool> _flag{false};
  std::mutex _mutex;
  std::condition_variable _condition;

public:
  void lock() {
    while (_flag.exchange(true, std::memory_order_acquire)) {
      std::unique_lock<std::mutex> lock(_mutex);
      _condition.wait(lock, [&]{ return !_flag.load(); });
    }
  }

  void unlock() {
    _flag.store(false, std::memory_order_release);
    _condition.notify_one();
  }
};

