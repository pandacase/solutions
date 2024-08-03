#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

//! @brief 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，
//! 其中 k 是非负数。
//!
//! @details
//! 尽可能想出更多的解决方案，尝试原地完成算法。
//! 
//! @example 
//! input:  nums = [1,2,3,4,5,6,7], k = 3
//! output:        [5,6,7,1,2,3,4]
//! 
//! @note 
//! 解法二：
//! 环状替换，只用一个 tmp 储存在当前步骤中被覆盖的值
//!
//! 解法三:
//! 首先翻转所有元素 
//! -> 翻转 [0,kmodn−1] 区间的元素
//! -> 翻转 [kmodn,n−1] 区间的元素
class Solution {
public:
  void rotate(std::vector<int>& nums, int k) {
    int size = nums.size();
    int offset = k % size;
    std::vector<int> tmp(offset);

    std::copy(nums.end() - offset, nums.end(), tmp.begin());
    std::copy_backward(nums.begin(), nums.end() - offset, nums.end());
    std::copy(tmp.begin(), tmp.end(), nums.begin());
  }

  // void rotate_2(std::vector<int>& nums, int k) {
  //   int size = nums.size();
  //   int offset = k % size;
  //   int times = std::gcd(offset, size);
  //   for (int i = 0; i < times; ++i) {
  //     int prevIdx = i;
  //     int prevVal = nums[prevIdx];
  //     do {
  //       int nextIdx = (prevIdx + offset) % size;
  //       std::swap(prevVal, nums[nextIdx]);
  //       prevIdx = nextIdx;
  //     } while (prevIdx != i);
  //   }
  // }

  // void rotate_3(std::vector<int>& nums, int k) {
  //   int size = nums.size();
  //   int offset = k % size;
    
  //   std::reverse(nums.begin(), nums.end());
  //   std::reverse(nums.begin(), nums.begin() + offset);
  //   std::reverse(nums.begin() + offset, nums.end());
  // }
};


int main() {
  Solution sol;
  std::vector<int> nums{-1,-100,3,99};
  int k = 2;
  sol.rotate(nums, k);

  for (auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
