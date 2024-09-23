
#include <vector>
#include <unordered_set>

//! @brief 
//! 判断是否存在一个新数组使得原数组 vec 中任意一个元素
//! 都可以由新数组中 2 个数的差得到。
//! 
class Solution {
public:
  bool
  ifExisted(std::vector<int>& vec) {
    int n = vec.size();
    if (n <= 1)
      return false;

    std::unordered_set<int> seen(vec.begin(), vec.end());
    if (seen.size() < n) 
      return true;

    // ...
  }
};