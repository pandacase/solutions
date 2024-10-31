#include <iostream>
#include <cmath>
#include <atomic>
#include <pthread.h>

// 条件变量和互斥锁
pthread_mutex_t mutex;
pthread_cond_t cond;

struct ThreadData {
  double a, b, c;
  double discriminat;
  bool discriminat_done = false;
  alignas(64) double root1, root2;
  alignas(64) std::atomic<bool> root1_done{false};
  alignas(64) std::atomic<bool> root2_done{false};
};

void* calDis(void* arg) {
  auto data = static_cast<ThreadData*>(arg);
  data->discriminat = data->b * data->b - 4 * data->a * data->c;

  pthread_mutex_lock(&mutex);
  data->discriminat_done = true;
  pthread_cond_broadcast(&cond);
  pthread_mutex_unlock(&mutex);

  return nullptr;
}

void* calRoot1(void* arg) {
  auto data = static_cast<ThreadData*>(arg);

  pthread_mutex_lock(&mutex);
  while (!data->discriminat_done) {
    // 需要传入 mutex 是因为，进入等待的时候解锁，离开等待时加锁
    pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);

  if (data->discriminat >= 0) {
    data->root1 = (-data->b + std::sqrt(data->discriminat)) / (2 * data->a);
  }
  data->root1_done.store(true);
  pthread_cond_signal(&cond);

  return nullptr;
}

void* calRoot2(void* arg) {
  auto data = static_cast<ThreadData*>(arg);

  pthread_mutex_lock(&mutex);
  while (!data->discriminat_done) {
    // 需要传入 mutex 是因为，进入等待的时候解锁，离开等待时加锁
    pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);

  if (data->discriminat >= 0) {
    data->root2 = (-data->b - std::sqrt(data->discriminat)) / (2 * data->a);
  }
  data->root2_done.store(true);
  pthread_cond_signal(&cond);

  return nullptr;
}

int main() {
  double a, b, c;
  std::cout << "Enter the args `a b c`:" << std::endl;
  std::cin >> a >> b >> c;
  ThreadData data = {a, b, c};

  pthread_mutex_init(&mutex, nullptr);
  pthread_cond_init(&cond, nullptr);

  pthread_t thrd_dis, thrd_root_1, thrd_root_2;
  pthread_create(&thrd_dis, nullptr, calDis, &data);
  pthread_create(&thrd_root_1, nullptr, calRoot1, &data);
  pthread_create(&thrd_root_2, nullptr, calRoot2, &data);

  pthread_mutex_lock(&mutex);
  while (data.root1_done.load() && data.root2_done.load()) {
    pthread_cond_wait(&cond, &mutex);
  }
  pthread_mutex_unlock(&mutex);

  if (data.discriminat >= 0) {
    std::cout << "Roots are real:" << std::endl;
    std::cout << "Root 1: " << data.root1 << std::endl;
    std::cout << "Root 2: " << data.root2 << std::endl;
  } else {
    std::cout << "Roots are complex (not real)." << std::endl;
  }

  pthread_join(thrd_dis, nullptr);
  pthread_join(thrd_root_1, nullptr);
  pthread_join(thrd_root_2, nullptr);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);

  return 0;
}