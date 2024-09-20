
#include <vector>
#include <iostream>

//! @brief 
//! 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//! 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//! 你可以假设除了整数 0 之外，这个整数不会以零开头。
//! 
//! @details 
//! 1 <= digits.length <= 100
//! 0 <= digits[i] <= 9
//!
//! @example
//! inputs: digits = [1,2,3]
//! output: [1,2,4]
//! 
//! inputs: digits = [0]
//! output: [1]
//! 
//! @note
//! 官方的思路是找最长的连续 9 后缀，全部置为 0，并在前一位 + 1。
//! 这样就不需要占用 O(2n) 了。
//!
class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    std::vector<int> res(n, 0);

    int carry = 1;
    for (int i = n - 1; i >= 0; --i) {
      res[i] = (digits[i] + carry) % 10;
      carry = (digits[i] + carry) / 10;
    }
    // 👇 性能最糟糕的地方 
    if (carry == 1) {
      res.insert(res.begin(), 1);
    }
    return res;
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
