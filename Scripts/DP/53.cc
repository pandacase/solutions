

#include <vector>
#include <algorithm>

//! @brief 
//! 给定一个整数数组 nums，找出一个具有最大和的连续子数组，返回其
//! 最大和。子数组是数组中的一个连续部分。
//! 
//! @details 
//! 1 <= nums.length <= 10^5
//! -10^4 <= nums[i] <= 10^4
//! 
//! @example 
//! input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//! output: 6
//! 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
//! 
//! input: nums = [1]
//! output: 1
//! 
//! input: nums = [5,4,-1,7,8]
//! output: 23
//! 解释: 连续子数组 [5,4,-1,7,8] 的和最大，为 23。
//! 
//! @note
//! 如果你已经实现复杂度为O(n)的解法，尝试使用更为精妙的分治法求解。//TODO
//! 
class Solution {
public:
  int 
  maxSubArray(std::vector<int>& nums) 
  {
    size_t n = nums.size();
    int curr = nums[0];

    int ans = nums[0];
    for (size_t i = 1; i < n; ++i) {
      curr = std::max(curr + nums[i], nums[i]);
      ans = std::max(ans, curr);
    }

    return ans;
  }
};