#include <vector>
#include <iostream>

#define REPEAT_TIME 2

//! @brief 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，
//! 使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
//!
//! @details
//! 不要使用额外的数组空间，你必须在原地修改输入数组并在使用
//! O(1) 额外空间的条件下完成。
//! 
//! @example 
//! input:  nums = [0,0,1,1,1,1,2,3,3]
//! output: 7, nums = [0,0,1,1,2,3,3]
//! 
//! @note 无
class Solution {
public:
  // int removeDuplicates(std::vector<int>& nums) {
  //   int size = nums.size();
  //   if (size == 0) return 0;
  //   if (size == 1) return 1;
    
  //   int left = 0;
  //   int times = REPEAT_TIME - 1;
  //   for (int right = 1; right < size; ++right) {
  //     if (nums[left] == nums[right] && times > 0) {
  //       nums[++left] = nums[right];
  //       times--;
  //     } else if (nums[left] != nums[right]) {
  //       nums[++left] = nums[right];
  //       times = REPEAT_TIME - 1;
  //     }
  //   }

  //   return left + 1;
  // }

  int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    for (int num : nums) {
      if (i < REPEAT_TIME || num > nums[i - REPEAT_TIME]) {
        nums[i++] = num;
      }
    }
    
    return i;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{1, 1, 2, 2, 2, 2, 2, 3};
  int ans = sol.removeDuplicates(nums);

  for (auto it = nums.begin(); it != nums.begin() + ans; it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
