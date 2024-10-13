
#include <iostream>
#include <vector>
#include <unordered_set>

struct vec_hash
{
  std::size_t 
  operator()(const std::vector<int>& vec) const 
  {
    std::size_t hash = 0;
    for (int val : vec) {
      //! @note 
      //! 经验设计：0x9e3779b9 是黄金混合数，
      //! 后面的部分也是为了让分布尽可能均匀
      hash ^= std::hash<int>{}(val) 
            + 0x9e3779b9 
            + (hash << 6) + (hash >> 2);
    }
    return hash;
  }
};

struct vec_cmp
{
  bool 
  operator()(
    const std::vector<int>& a, 
    const std::vector<int>& b) const 
  {
    //! @note
    //! STL 自带的 operator== 基本都是检查容器内容是否相等
    //! 而 JavaScript 中的 === 语义对应到 C++ 中
    //! 是由程序员手动取出 2 个容器的地址来比较
    return a == b;
  }
};


int main() {
  std::unordered_set<
    std::vector<int>, vec_hash, vec_cmp
  > vec_set;

  vec_set.insert({1, 2, 3});
  vec_set.insert({1, 2, 3});

  std::cout << vec_set.size() << std::endl;
  return 0;
}