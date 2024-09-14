
#include <vector>

//! @brief 
//! 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
//! 请你找出给定目标值在数组中的开始位置和结束位置。
//! 
//! @details
//! 0 <= nums.length <= 105
//! -109 <= nums[i] <= 109
//! nums 是一个非递减数组
//! -109 <= target <= 109
//! 
//! @example 
//! input:  nums = [5,7,7,8,8,10], target = 8
//! output: [3,4]
//! 
class Solution {
public:
  std::vector<int> searchRange(std::vector<int>& vec, int value) {
    return {firstEqual(vec, value), lastEqual(vec, value)};
  }

private:
  int firstEqual(std::vector<int>& vec, int value) {
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

    if (low < vec.size() && vec[low] == value)
      return low;
    else
      return -1;
  }

  int lastEqual(std::vector<int>& vec, int value) {
    if (vec.empty())
      return -1;

    int low = 0, high = vec.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (vec[mid] <= value)
        low = mid + 1;
      else
        high = mid - 1;
    }

    if (low - 1 >= 0 && vec[low - 1] == value)
      return low - 1;
    else
      return -1;
  }
};