
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

//! @brief 
//! 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
//! 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//! 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//! 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下，
//! 一夜之内能够偷窃到的最高金额。
//! 
//! @details 
//! 1 <= nums.length <= 100
//! 0 <= nums[i] <= 400
//! 
//! @example
//! inputs: [1,2,3,1]
//! output: 4
//! 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//! 
//! inputs: [2,7,9,3,1]
//! output: 12
//! 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，
//! 接着偷窃 5 号房屋 (金额 = 1)。
//! 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
//! 
//! @note
//! 因为在选择房屋的时候，至多只可能有连续 2 个房屋没有去偷
//! （如果是 3 个的话，那中间那一个就可以偷了）
//! 所以 dp 计算的时候只需要考虑 i - 2 和 i - 3 中哪个大再加上本房屋
//! 以及最终遍历完数组后，最大的结果是在 n - 1 和 n - 2 中找的。
//!
class Solution {
public:
  int 
  rob(std::vector<int>& nums) 
  {
    size_t n = nums.size();
    if (n == 1)
      return nums[0];
    if (n == 2)
      return std::max(nums[0], nums[1]);
    
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    int max = std::max({dp[2], dp[1]});
    for (int i = 3; i < n; ++i) {
      dp[i] = std::max(dp[i - 2], dp[i - 3]) + nums[i];
    }
    return std::max(dp[n - 1], dp[n - 2]);
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
