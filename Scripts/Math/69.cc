
#include <vector>
#include <iostream>

//! @brief 
//! 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//! 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//! 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
//! 
//! @details 
//! 0 <= x <= 231 - 1
//!
//! @example
//! inputs: x = 4
//! output: 2
//! 
//! inputs: x = 4
//! output: 2
//! 
//! @note
//! ❗注意，使用 uint64_t res 去接收变量结果无法解决整数溢出的问题！
//! ❗这是因为在等式的右边，临时右值仍然是一个 int，这个结果是会发生溢出的。
//!
class Solution {
public:
  int 
  mySqrt(int x) 
  {
    if (x == 0)
      return 0;
    else if (x < 4)
      return 1;
      
    int low = 1, high = x / 2;
    int ans = 0;
    // high = std::min(46340, high);

    while (low <= high) {
      int root = low + (high - low) / 2;
      //❗ uint64_t res = root * root; 
      if ((uint64_t)root * root <= x) {
        ans = std::max(ans, root);
        low = root + 1;
      } else {
        high = root - 1;
      }
    }

    return ans;
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
