
#include <vector>
#include <stack>

//! @brief 
//! 峰值元素是指其值严格大于左右相邻值的元素。
//! 给你一个整数数组 nums，找到峰值元素并返回其索引。
//! 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
//! 你可以假设 nums[-1] = nums[n] = -∞ 。
//! 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
//! 
//! @details
//! 1 <= nums.length <= 1000
//! -231 <= nums[i] <= 231 - 1
//! 对于所有有效的 i 都有 nums[i] != nums[i + 1]
//! 
//! @example 
//! input:  nums = [1,2,3,1]
//! output: 2
//! 
//! input:  nums = [1,2,1,3,5,6,4]
//! output: 1 或 5 
//! 
//! 
class Solution {
public:
  int 
  findPeakElement(std::vector<int>& nums) 
  {
    int low = 0, high = nums.size();
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (checkType(nums, mid) == Type::peak) {
        return mid;
      } else if (checkType(nums, mid) == Type::asc) {
        low = mid + 1;
      } else if (checkType(nums, mid) == Type::desc) {
        high = mid - 1;
      }
    }
    return -1;
  }

private:
  enum class Type { peak, asc, desc };

  Type 
  checkType(std::vector<int>& nums, size_t index)
  {
    size_t n = nums.size();
    if (n == 1)
      return Type::peak;
    if (index == 0)
      return nums[index] > nums[index + 1] ? Type::peak : Type::asc;
    if (index == n - 1)
      return nums[index] > nums[index - 1] ? Type::peak : Type::desc;

    if (nums[index] > nums[index - 1]) {
      if (nums[index] > nums[index + 1])
        return Type::peak;
      else
        return Type::asc;
    } else {
      return Type::desc;
    }
  }
};