#include <iostream>
#include <cmath>
#include <atomic>
#include <functional>
#include <random>
#include <pthread.h>

struct ThreadData {
  std::function<double(double)>* func_analysis;
  double begin, end;
  size_t local_upper;
  size_t local_count;
};

void* countPoints(void* arg) {
  auto data = static_cast<ThreadData*>(arg);
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(data->begin, data->end);
  
  for (size_t i = 0; i < data->local_upper; ++i) {
    double rand_x = dis(gen), rand_y = dis(gen);
    if (rand_y <= (*data->func_analysis)(rand_x)) {
      data->local_count += 1;
    }
  }

  return nullptr;
}

int main() {
  const size_t GLOBAL_UPPER = 1000000;
  const size_t THRD_NUM = 8;
  auto func = [](double x) { return x * x; };
  std::function<double(double)> func_analysis = func;

  std::vector<pthread_t> thrds(THRD_NUM);
  std::vector<ThreadData> args(THRD_NUM);
  size_t per_thrd = GLOBAL_UPPER / THRD_NUM;
  size_t remainder = GLOBAL_UPPER % THRD_NUM;
  for (size_t i = 0; i < THRD_NUM; ++i) {
    size_t local_upper = i < remainder ? per_thrd + 1 : per_thrd;
    args[i].func_analysis = &func_analysis;
    args[i].begin = 0.0;
    args[i].end = 1.0;
    args[i].local_upper = local_upper;
    args[i].local_count = 0;

    pthread_create(&thrds[i], nullptr, countPoints, &args[i]);
  }

  size_t global_count = 0;
  for (size_t i = 0; i < THRD_NUM; ++i) {
    pthread_join(thrds[i], nullptr);
    global_count += args[i].local_count;
  }

  double res = (double)global_count / GLOBAL_UPPER;
  std::cout << "RESULT: " << res << std::endl;
  return 0;
}
