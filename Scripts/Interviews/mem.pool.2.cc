
#include <iostream>
#include <mutex>
#include <vector>


class memory_pool {
public:




private:
  size_t _block_size;
  size_t _block_cnt;
  std::vector<char*> _free_blocks;
  std::mutex _mutex;
}