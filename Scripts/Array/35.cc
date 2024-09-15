
#include <vector>

//! @brief 
//! 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//! 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//! 
//! @details
//! 1 <= nums.length <= 104
//! -104 <= nums[i] <= 104
//! nums 为 无重复元素 的 升序 排列数组
//! -104 <= target <= 104
//! 
//! @example 
//! input:  nums = [1,3,5,6], target = 5
//! output: 2
//! 
class Solution {
public:
  int searchInsert(std::vector<int>& vec, int value) {
    if (vec.empty())
      return -1;

    int low = 0, high = vec.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (vec[mid] >= value)
        high = mid - 1;
      else
        low = mid + 1;
    }

    if (low < vec.size() && vec[low] >= value)
      return low;
    else
      return vec.size();
  }
};