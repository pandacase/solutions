#include <vector>
#include <iostream>


//! @brief 给你一个非严格递增排列的数组 nums ，请你原地删除
//! 重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//! 元素的相对顺序应该保持一致 。然后返回 nums 中唯一元素的个数。
//! 
//! @details
//! 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情:
//! 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，
//! 并按照它们最初在 nums 中出现的顺序排列。
//! nums 的其余元素与 nums 的大小不重要。
//! 
//! @example 
//! input:  nums = [0,0,1,1,1,2,2,3,3,4]
//! output: 5, nums = [0,1,2,3,4]
//! 
//! @note 无
class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    if (size == 1) return 1;
    
    int left = 0;
    for (int right = 0; right < size; ++right) {
      if (nums[left] != nums[right]) {
        nums[++left] = nums[right];
      }
    }

    return left + 1;
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
