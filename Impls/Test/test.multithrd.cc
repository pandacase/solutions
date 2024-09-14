#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

// 共享缓冲区
std::queue<int> buffer;
const unsigned int max_buffer_size = 5;  // 缓冲区最大容量

// 互斥锁和条件变量
std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;

// 生产者函数
void producer(int id) {
  for (int i = 0; i < 10; ++i) {
    std::unique_lock<std::mutex> lock(mtx);

    cv_producer.wait(lock, []() {
      return buffer.size() < max_buffer_size;
    });

    buffer.push(i);

    cv_consumer.notify_one();
  }
}

// 消费者函数
void consumer(int id) {
  while (true) {
    std::unique_lock<std::mutex> lock(mtx);

    cv_consumer.wait(lock, []() {
      return !buffer.empty();
    });

    auto product = buffer.front(); buffer.pop();
    std::cout << product << std::endl;

    cv_producer.notify_one();
  }
}

int main() {
  // 创建生产者线程和消费者线程
  std::thread producers[] = {
    std::thread(producer, 1),
    std::thread(producer, 2)
  };
  
  std::thread consumers[] = {
    std::thread(consumer, 1),
    std::thread(consumer, 2)
  };

  // 等待生产者线程完成
  for (auto& p : producers) {
    p.join();
  }

  // 主线程延迟一段时间后终止消费者线程
  std::this_thread::sleep_for(std::chrono::seconds(5));
  for (auto& c : consumers) {
    c.join();
  }

  return 0;
}
