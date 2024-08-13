#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 给定一个含有 n 个正整数的数组和一个正整数 target 。
//! 找出该数组中满足其总和大于等于 target 的长度最小的子数组
//! [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
//! 如果不存在符合条件的子数组，返回 0 。
//! 
//! @details 
//! 1 <= target <= 10e9
//! 1 <= nums.length <= 10e5
//! 1 <= nums[i] <= 10e5
//! 
//! @example 
//! input:  target = 7, nums = [2,3,1,2,4,3]
//! output: 2
//! 子数组 [4,3] 是该条件下的长度最小的子数组。
//! input:  target = 4, nums = [1,4,4]
//! output: 1
//! input:  target = 11, nums = [1,1,1,1,1,1,1,1]
//! output: 0
//! 
//! @note
//! 其他方法：前缀和 + 二分查找
class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int size = nums.size();
    int left = 0, right = 0;
    int sum = nums[left], minLength = 10e5 + 1;
    while (left <= right && right < size) {
      if (sum < target) {
        right += 1;
        if (right < size)
          sum += nums[right];
      } else {
        minLength = std::min(minLength, right - left + 1);
        sum -= nums[left];
        left += 1;
      }
    }
    return minLength == 10e5 + 1 ? 0 : minLength;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums{12,28,83,4,25,26,25,2,25,25,25,12};
  auto ans = sol.minSubArrayLen(213, nums);
  
  std::cout << ans << std::endl;
}
