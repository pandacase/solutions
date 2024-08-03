#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

//! @brief 给定一个大小为 n 的数组 nums ，返回其中的多数元素。
//! 多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//! 
//! @example 
//! input:  nums = [2,2,1,1,1,2,2]
//! output: 2
//! 
//! @note 如果一个数组有大于一半的数相同，那么任意删去两个不同的数字，
//! 新数组还是会有相同的性质。
class Solution {
public:
  // int majorityElement(std::vector<int>& nums) {
  //   sort(nums.begin(), nums.end());
  //   return nums[nums.size() / 2];
  // }

  int majorityElement(std::vector<int>& nums) {
    int size = nums.size();
    while(1) {
      int majority = nums[rand() % size];
      int cnt = 0;
      for (int i = 0; i < size; ++i) {
        if (nums[i] == majority) 
          cnt++;
      }
      if (cnt > size / 2)
        return majority;
    }
  }
};

int main() {
  Solution sol;
  std::vector<int> nums{1, 2, 2, 2, 2, 3, 3};
  int ans = sol.majorityElement(nums);

  std::cout << ans << std::endl;
}
