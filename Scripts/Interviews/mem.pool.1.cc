
#include <unordered_map>
#include <iostream>
#include <vector>


class MemoryPool {
private:
  struct Block {
    Block* next;
  };

  Block* freeList; // 空闲块链表的头
  size_t blockSize; // 每个内存块的大小
  size_t poolSize; // 内存池大小
  void* pool; // 整个内存池

public:
  MemoryPool(size_t blockSize, size_t poolSize) 
  : blockSize(blockSize), poolSize(poolSize) {
    pool = operator new(blockSize * poolSize); // 分配整块内存
    freeList = nullptr;

    // 初始化空闲链表
    for (size_t i = 0; i < poolSize; ++i) {
      auto block = reinterpret_cast<Block*>(
        static_cast<char*>(pool) + i * blockSize
      );
      block->next = freeList;
      freeList = block; // 将块添加到空闲链表中
    }
  }

  ~MemoryPool() {
    operator delete(pool); // 释放内存池
  }

  void* allocate() {
    if (freeList == nullptr) {
      throw std::bad_alloc();
    }

    // 从空闲链表中获取第一个块
    Block* block = freeList;
    freeList = freeList->next; // 更新空闲链表的头
    return block;
  }

  void deallocate(void* ptr) {
    // 将释放的块放回空闲链表
    Block* block = reinterpret_cast<Block*>(ptr);
    block->next = freeList;
    freeList = block;
  }
};


int main() {
  MemoryPool pool(32, 10);    // 创建一个内存池，每个块大小为 32 字节，有 10 个块
  void* p = pool.allocate();  // 从内存池分配一个内存块
  int* data = new (p) int[5]; // 在这块内存上存放一个整型数组

  data[0] = 5;
  data[1] = data[0] + 1;
  std::cout << data[1] << std::endl;
  pool.deallocate(p);
}