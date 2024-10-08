#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

//! @brief 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示
//! 一支给定股票第 i 天的价格。
//! 你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子
//! 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//! 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//!
//! @details
//! 1 <= prices.length <= 105
//! 0 <= prices[i] <= 104
//! 
//! @example 
//! input:  prices = [7,1,5,3,6,4]
//! output:        5
//! input:  prices = [7,6,4,3,1]
//! output:        0
//! 
//! @note 
//! 遍历每天的时候考虑：如果是今天买入，则在今天往后最大利润那天卖出即可。
//! 此时 max value 的维护是从后往前的，也可以做出来。
//! 或者反向考虑，从前往后遍历，每天考虑若在今天卖出，则应在今天往前哪天买入
class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int size = prices.size();
    int minVal = std::numeric_limits<int>::max();
    int maxAns = 0;

    for (int i = 0; i < size; ++i) {
      minVal = std::min(minVal, prices[i]);
      maxAns = std::max(maxAns, prices[i] - minVal);
    }

    return maxAns;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{7,1,5,3,6,4};
  int ans = sol.maxProfit(nums);

  std::cout << ans << std::endl;
}
