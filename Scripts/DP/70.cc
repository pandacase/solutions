
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

//! @brief 
//! 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//! 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//! 
//! @details 
//! 1 <= n <= 45
//! 
//! @example
//! inputs: n = 2
//! output: 2
//! 有两种方法可以爬到楼顶。
//! 1. 1 阶 + 1 阶
//! 2. 2 阶
//! 
//! inputs: n = 3
//! output: 3
//! 有三种方法可以爬到楼顶。
//! 1. 1 阶 + 1 阶 + 1 阶
//! 2. 1 阶 + 2 阶
//! 3. 2 阶 + 1 阶
//! 
//! @note
//!
class Solution {
public:
  int 
  climbStairs(int n) 
  {
    if (n == 1)
      return 1;
    else if (n == 2)
      return 2;

    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    int prevprev = 1, prev = 2, curr = 0;
    for (int i = 3; i <= n; ++i) {
      curr = prevprev + prev;
      prevprev = prev;
      prev = curr;
    }
    return curr;
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
