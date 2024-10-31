#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <pthread.h>

void randomInit(
  std::vector<double>& m
) {
  size_t size = m.size();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);
  for (size_t i = 0; i < size; ++i) {
    m[i] = dis(gen);
  }
}

struct ThreadData {
  size_t startRow; // 当前线程计算的起始行
  size_t endRow;   // 当前线程计算的结束行
  const std::vector<double> *A;
  const std::vector<double> *B;
  std::vector<double> *C;
  size_t m, n, k;
};

// 矩阵乘法计算函数（每个线程使用）
void* multiplyRowRange(void* arg) {
  ThreadData *data = static_cast<ThreadData*>(arg);
  for (size_t i = data->startRow; i < data->endRow; ++i) {
    for (size_t j = 0; j < data->k; ++j) {
      double sum = 0.0;
      for (size_t l = 0; l < data->n; ++l) {
        sum += (*data->A)[i * data->n + l] * (*data->B)[l * data->k + j];
      }
      (*data->C)[i * data->k + j] = sum;
    }
  }
  return nullptr;
}

// 矩阵乘法并行实现
void 
parallelMatrixMultiply(
  const std::vector<double>& A, 
  const std::vector<double>& B, 
  std::vector<double>& C, 
  size_t m, size_t n, size_t k, size_t numThreads
) {
  std::vector<pthread_t> threads(numThreads);
  std::vector<ThreadData> threadData(numThreads);

  // 每个线程的行数
  size_t rowsPerThread = m / numThreads;
  size_t remainingRows = m % numThreads;

  size_t currentRow = 0;
  for (size_t i = 0; i < numThreads; ++i) {
    size_t startRow = currentRow;
    size_t endRow = startRow + rowsPerThread + (i < remainingRows ? 1 : 0);
    currentRow = endRow;

    threadData[i] = {startRow, endRow, &A, &B, &C, m, n, k};

    pthread_create(&threads[i], nullptr, multiplyRowRange, &threadData[i]);
  }

  for (int i = 0; i < numThreads; ++i) {
    pthread_join(threads[i], nullptr);
  }
}

int main() {
  std::vector<size_t> num_thrds_arr = {1, 2, 4, 8};
  std::vector<size_t> size_arr = {512, 1024, 2048};

  for (size_t i = 0; i < num_thrds_arr.size(); ++i) {
    size_t num_thrds = num_thrds_arr[i];
    std::cout << num_thrds << " | ";

    for (size_t j = 0; j < size_arr.size(); ++j) {
      size_t size = size_arr[j];

      // 初始化矩阵 A 和 B
      std::vector<double> A(size * size);
      randomInit(A);
      std::vector<double> B(size * size);
      randomInit(B);
      std::vector<double> C(size * size);

      auto start = std::chrono::high_resolution_clock::now();
      parallelMatrixMultiply(A, B, C, size, size, size, num_thrds);
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<float> duration = end - start;

      // 输出结果矩阵 C 耗时
      std::cout << duration.count() << " | ";
    }
    std::cout << std::endl;
  }

  return 0;
}
