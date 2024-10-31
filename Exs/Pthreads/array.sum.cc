#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <pthread.h>

// 数组大小
const size_t ARR_SIZE = 10000000;
// 线程数
const size_t THRD_NUM = 8;
// 全局索引
size_t global_index = 0;
// 计算结果
long long sum;
// 互斥锁
pthread_mutex_t mutex;

void* sumArray(void* arg) {
  auto arr = static_cast<std::vector<int>*>(arg);
  while (true) {
    // 临界区开始
    pthread_mutex_lock(&mutex);
    if (global_index >= ARR_SIZE) {
      pthread_mutex_unlock(&mutex);
      break;
    }
    for (int i = 0; i < 10; ++i) {
      sum += (*arr)[global_index++];
    }
    // 临界区结束
    pthread_mutex_unlock(&mutex);
  }
  return nullptr;
}

int main() {
  std::vector<int> arr(ARR_SIZE, 1);
  std::vector<pthread_t> thrds(THRD_NUM);

  pthread_mutex_init(&mutex, nullptr);

  auto start = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < THRD_NUM; ++i) {
    pthread_create(&thrds[i], nullptr, sumArray, &arr);
  }
  for (size_t i = 0; i < THRD_NUM; ++i) {
    pthread_join(thrds[i], nullptr);
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> duraction = end - start;
  
  std::cout << "Result: " << sum << std::endl;
  std::cout << "Time Costed: " << duraction.count() << std::endl;

  pthread_mutex_destroy(&mutex); // 销毁互斥锁
  return 0;
}