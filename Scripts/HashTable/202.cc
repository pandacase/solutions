#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

//! @brief 
//! 编写一个算法来判断一个数 n 是不是快乐数。
//! 「快乐数」 定义为：
//! 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//! 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//! 如果这个过程 结果为 1，那么这个数就是快乐数。
//! 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//! 
//! @details 
//! 1 <= n <= 2^31 - 1
//! 
//! @example 
//! input:  n = 19
//! output: true
//! 1^2 + 9^2 = 82
//! 8^2 + 2^2 = 68
//! 6^2 + 8^2 = 100
//! 1^2 + 0^2 + 0^2 = 1
//! 
//! input:  n = 2
//! output: false
//! 
//! @note
//!
class Solution {
public:
  bool isHappy(int n) {
    std::unordered_set<int> numbers;
    while (true) {
      n = getSumOfSquares(n);
      
      if (n == 1)
        return true;
      else if (numbers.count(n))
        return false;
      else
        numbers.insert(n);
    }
  }

  int getSumOfSquares(int num) {
    int res = 0;
    while (num > 0) {
      int digit = num % 10;
      res += digit * digit;
      num /= 10;
    }
    return res;
  }
};

int main() {
  Solution sol;
  auto ans = sol.isHappy(2);

  //! 0  
  std::cout << ans << std::endl;

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
