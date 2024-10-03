
#include <vector>
#include <stack>

//! @brief 
//! 整数数组 nums 按升序排列，数组中的值 互不相同 。
//! 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）
//! 上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], 
//! nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 
//! 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
//! 
//! 给你旋转后的数组 nums 和一个整数 target，如果 nums 中存在这个目标值 target，
//! 则返回它的下标，否则返回 -1 。
//! 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
//! 
//! @details
//!  <= nums.length <= 5000
//! -104 <= nums[i] <= 104
//! nums 中的每个值都 独一无二
//! 题目数据保证 nums 在预先未知的某个下标上进行了旋转
//! -104 <= target <= 104
//! 
//! @example 
//! input:  nums = [4,5,6,7,0,1,2], target = 0
//! output: 4
//! 
//! input:  nums = [4,5,6,7,0,1,2], target = 3
//! output: -1
//! 
class Solution {
public:
  int 
  search(std::vector<int>& nums, int target) 
  {
    size_t n = nums.size();
    size_t low = 0, high = n - 1;
    while (low <= high) {
      size_t mid = low + (high - low) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[n - 1]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};