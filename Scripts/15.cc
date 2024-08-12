#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

//! @brief 给你一个整数数组 nums ，判断是否存在三元组 
//! [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
//! 同时还满足 nums[i] + nums[j] + nums[k] == 0 。
//! 请你返回所有和为 0 且不重复的三元组。
//! 注意：答案中不可以包含重复的三元组。
//! 
//! @details 
//! n == height.length
//! 2 <= n <= 10e5
//! 0 <= height[i] <= 10e4
//! 
//! @example 
//! input:  nums = [-1,0,1,2,-1,-4]
//! output: [[-1,-1,2],[-1,0,1]]
//!   nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//!   nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//!   nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//!   不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//!   注意，输出的顺序和三元组的顺序并不重要。
//! input:  nums = [0,1,1]
//! output: []
//!   唯一可能的三元组和不为 0 。
//! input:  nums = [0,0,0]
//! output: [[0,0,0]]
//!   唯一可能的三元组和为 0 。
//! 
//! @note
//! 
class Solution {
public:
  std::vector<std::vector<int>> 
  threeSum(std::vector<int>& nums) 
  {
    std::sort(nums.begin(), nums.end());

    int size = nums.size();
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < size; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int sum = 0 - nums[i];

      int left = i + 1, right = size - 1;
      while (left < right) {        
        if (nums[left] + nums[right] < sum)
          left += 1;
        else if (nums[left] + nums[right] > sum)
          right -= 1;
        else {
          ans.push_back({nums[i], nums[left], nums[right]});
          left += 1;
          right -= 1;
          while (left < size && nums[left] == nums[left - 1]
              && right >= 0 && nums[right] == nums[right + 1]) {
            left += 1;
            right -= 1;
          }
        };
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<int> height{-1,0,1,2,-1,-4};
  auto ans = sol.threeSum(height);
  
  for (auto vec : ans) {
    for (auto e : vec) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
  }
    
}
