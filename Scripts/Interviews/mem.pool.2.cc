
#include <iostream>
#include <mutex>
#include <vector>
#include <array>
#include <thread>
#include <string>

#define BLOCK_SIZE 1024
#define BLOCK_COUNT 10
#define THREAD_NUM 5

///////////////////////////////////////////////////////////////////

class memory_pool {
public:
  memory_pool(size_t block_size, size_t block_cnt)
   : _block_size(block_size), _block_cnt(block_cnt) {
    for (size_t i = 0; i < _block_cnt; ++i) {
      _free_blocks.push_back(static_cast<char*>(::operator new(_block_size)));
    }
  }

  ~memory_pool() {
    for (auto block : _free_blocks) {
      ::operator delete(block);
    }
  }

  void* allocate() {
    std::lock_guard<std::mutex> lock(_mutex);
    if (_free_blocks.empty()) {
      throw std::bad_alloc();
    }
    void* block = _free_blocks.back();
    _free_blocks.pop_back();
    return block;
  }

  void deallocate(void* block) {
    std::lock_guard<std::mutex> lock(_mutex);
    _free_blocks.push_back(static_cast<char*>(block));
  }

private:
  size_t _block_size;
  size_t _block_cnt;
  std::vector<char*> _free_blocks;
  std::mutex _mutex;
};

///////////////////////////////////////////////////////////////////

template <typename T>
class PoolAllocator {
public:
  using value_type = T;

  PoolAllocator(memory_pool& pool) : pool_(pool) {}

  template <typename U>
  PoolAllocator(const PoolAllocator<U>& other) : pool_(other.pool_) {}

  T* allocate(std::size_t n) {
    if (n != 1) {
      throw std::bad_alloc();  // 该内存池分配器只支持单个对象分配
    }
    return static_cast<T*>(pool_.allocate());
  }

  void deallocate(T* p, std::size_t) noexcept {
    pool_.deallocate(p);
  }

private:
  memory_pool& pool_;
};

// PoolAllocator 的类型比较操作
template <typename T, typename U>
bool operator==(const PoolAllocator<T>&, const PoolAllocator<U>&) { return true; }
template <typename T, typename U>
bool operator!=(const PoolAllocator<T>&, const PoolAllocator<U>&) { return false; }


///////////////////////////////////////////////////////////////////

void thread_func(memory_pool& pool) {
  for (int i = 0; i < 10; ++i) {
    void* block = pool.allocate();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    auto arr = new (block) std::array<int, 5>{1, 2, 3, 4, 5};
    std::cout << *(arr->begin()) << std::endl;

    pool.deallocate(block);
  }
}

///////////////////////////////////////////////////////////////////

int main() {

  memory_pool pool1(BLOCK_SIZE, BLOCK_COUNT);
  std::thread thrds[THREAD_NUM];
  for (int i = 0; i < THREAD_NUM; ++i) {
    thrds[i] = std::thread(thread_func, std::ref(pool1));
  }
  for (int i = 0; i < 5; ++i) {
    thrds[i].join();
  }


  memory_pool pool2(sizeof(int), 10); // 初始化内存池，支持 10 个 int 大小的块
  PoolAllocator<int> allocator(pool2); // 创建分配器对象

  std::vector<int, PoolAllocator<int>> vec(allocator); // 正确使用自定义分配器

  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  for (int i : vec) {
    std::cout << i << std::endl;
  }

  return 0;
}

