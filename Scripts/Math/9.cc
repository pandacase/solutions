
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

//! @brief 
//! 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//! 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//! 例如，121 是回文，而 123 不是。
//! 
//! @details 
//! -231 <= x <= 231 - 1
//!
//! @example
//! inputs: x = 121
//! output: true
//! 
//! inputs: x = -121
//! output: false
//! 
//! @note
//! 有趣的简单题目。
//!
class Solution {
public:
  bool 
  isPalindrome(int x) 
  {
    if (x < 0 || (x != 0 && x % 10 == 0))
      return false;
    
    int reverted_num = 0;
    while (x > reverted_num) {
      reverted_num *= 10;
      reverted_num += x % 10;
      x /= 10;
    }

    return x == reverted_num || x == reverted_num / 10;
  }
};


int main() {

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
