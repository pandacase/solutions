
#include <vector>
#include <iostream>

//! @brief 
//! 给定一个长度为 n 的数组，预先按照升序排列，经过 1 到 n 次旋转后，
//! 得到输入数组。请找出并返回数组中的最小元素。
//! 
//! 数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次的结果为数组 
//! [a[n-1], a[0], a[1], a[2], ..., a[n-2]]。
//! 
//! 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
//! 
//! @details 
//! - n == nums.length
//! - 1 <= n <= 5000
//! - -5000 <= nums[i] <= 5000
//! - nums 中的所有整数互不相同
//! - nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
//! 
//! @example 
//! input: nums = [3,4,5,1,2]
//! output: 1
//! 解释: 原数组为 [1,2,3,4,5]，旋转 3 次得到输入数组。
//! 
//! input: nums = [4,5,6,7,0,1,2]
//! output: 0
//! 解释: 原数组为 [0,1,2,4,5,6,7]，旋转 3 次得到输入数组。
//! 
//! input: nums = [11,13,15,17]
//! output: 11
//! 解释: 原数组为 [11,13,15,17]，旋转 4 次得到输入数组。
//! 
//! @note
//! 这是目前为止，遇到的唯一一道，终止条件是 low < high 而不是 low <= high
//! 这令我感到不适，因为即使是第 222 题的 二分查找 + 二进制编码 解法
//! 虽然官方题解用的是 low < high 的条件，但是我仍然使用 low <= high 解决了
//! 在很长一段时间里我都认为 low <= high 是所有二分查找都可以适用的条件
//! 而且在 low <= high 的条件下，最终循环停止时一定满足 low = high + 1
//! 这个 low 和 high 之间的关系可以帮助我完成二分查找这个算法的各种变体。
//! 
//! 之后经过分析，这题本质上是因为我们需要一个 high = mid 而不是
//! high = mid - 1 的迭代方式。否则会让接下来的 high 完全进入到左侧的大值区域
//! 一旦 high 进入了左侧的大值区域，那么 nums[mid] < nums[high] 这个判定方法
//! 就会完全失效，接下来无论如何都找不到最大值了。
//! 先有了 high = mid 的迭代方式，最后才决定了外层的循环条件是 low < high。
//! 
//! 另外为什么是考虑将 mid 与 high 比较而不是 mid 与 low 比较呢？
//! 因为最小值是出现在右侧的小值区域的，这意味着最终一定会出现 low 跨过了边界线
//! 的情况出现，这会导致 nums[low] < nums[mid] 这种条件失效。
//! 
//! 总结：这题在所有涉及二分查找中的题是属于比较特殊的，可以特殊记忆。
//! 而其他大部分二分查找题及其变体仍然可以保持最经典的三要素写法：
//! 1. while (low <= high)
//! 2. high = mid - 1;
//! 3. low = mid + 1;
//! 
class Solution {
public:
  static int 
  findMin(std::vector<int>& nums) 
  {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < nums[high]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return nums[high];
  }
};

int
main()
{
  std::vector<int> nums{4,5,1,2,3};
  std::cout << Solution::findMin(nums) << std::endl;

}