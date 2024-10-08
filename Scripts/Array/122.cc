#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 给你一个整数数组 prices ，其中 prices[i] 表示
//! 某支股票第 i 天的价格。
//! 在每一天，你可以决定是否购买 和/或 出售股票。
//! 你在任何时候最多只能持有一股股票。
//! 你也可以先购买，然后在同一天出售。
//! 返回你能获得的最大利润 。
//!
//! @details
//! 1 <= prices.length <= 3 * 104
//! 0 <= prices[i] <= 104
//! 
//! @example 
//! input:  prices = [7,1,5,3,6,4]
//! output:        7
//! 在第2天（股票价格 = 1）的时候买入，在第3天（股票价格 = 5）
//! 的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
//! 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天
//! （股票价格 = 6）的时候卖出, 获得利润 = 6 - 3 = 3。
//! 最大总利润为 4 + 3 = 7 。
//! 
//! @note 
//! 每天都可以在出售之后重新买入，故只需要把所有增量情况算入即可
class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int size = prices.size();
    int profit = 0;
    for (int i = 1; i < size; ++i) {
      profit += std::max(0, prices[i] - prices[i - 1]);
    }
    return profit;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{7,1,5,3,6,4};
  int ans = sol.maxProfit(nums);

  std::cout << ans << std::endl;
}
