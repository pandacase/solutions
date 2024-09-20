
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

//! @brief 
//! 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//! 计算并返回可以凑成总金额所需的 最少的硬币个数 。
//! 如果没有任何一种硬币组合能组成总金额，返回 -1 。
//! 你可以认为每种硬币的数量是无限的。
//! 
//! @details 
//! 1 <= coins.length <= 12
//! 1 <= coins[i] <= 2^31 - 1
//! 0 <= amount <= 10^4
//!
//! @example
//! inputs: coins = [1, 2, 5], amount = 11
//! output: 3 (11 = 5 + 5 + 1)
//! 
//! inputs: coins = [2], amount = 3
//! output: -1
//! 
//! @note
//! 为什么不能先从大到小排序，然后逐个取余？
//! 因为这与罗马数字转换不同，罗马数字有 "1" 这个整数最小值
//! 但是 coins 里面不一定有面值为 1 的硬币。
//! 比如有 coins = [5, 2], amount = 8
//! 显然要全部取 2 才能兑换零钱，但是遍历第一种硬币之后，amount 只剩下 3 不被 2 整除
//! 所以这一题最后还是需要动态规划来完成。
//!
class Solution {
public:
  int 
  coinChange(std::vector<int>& coins, int amount) 
  {
    int n_coins = coins.size();
    const int max_amount = amount + 1;
    std::vector<int> dp(amount + 1, max_amount);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < n_coins; ++j) {
        if (i >= coins[j])
          dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
      }
    }
    return dp[amount] == max_amount ? -1 : dp[amount];
  }
};


int main() {
  std::vector<int> coins{186, 419, 83, 408};
  Solution sol;
  auto ans = sol.coinChange(coins, 6249);

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
