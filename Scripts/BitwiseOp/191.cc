
#include <iostream>

//! @brief 
//! 编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 
//! 设置位的个数（也被称为汉明重量）。
//! 
//! @details 
//! 1 <= n <= 2^31 - 1
//! 
//! @note
//! 
class Solution {
public:
  int 
  hammingWeight(int n) 
  {
    int cnt = 0;
    while (n > 0) {
      cnt += n & 1;
      n >>= 1;
    }
    return cnt;
  }
};



int main() {
  Solution sol;
  auto ans = sol.hammingWeight(11);

  // print link
  std::cout << ans << std::endl;
}
