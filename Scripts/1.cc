#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>


//! @brief 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 
//! 和为目标值 target 的那 两个 整数，并返回它们的数组下标。
//!
//! @details
//! 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现
//! 你可以按任意顺序返回答案。
//! 
//! @example 
//! input:  nums = [2, 4, 11, 3], target = 6
//! output: ans = [0, 1]
//! 
//! @note 可以只使用一次遍历
//! 因为返回的结果只有一对，所以遍历到第二个目标的时候只需要查看第一个目标是否在集合中
//! 所以不需要关心两个算子是否相等导致键重复的问题
class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, const int target) {
    std::unordered_map<int, int> index;
    int lastIndex = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (index.count(nums[i]) > 0) {
        lastIndex = index[nums[i]];
      }
      index[nums[i]] = i;
    }
    
    int ans_index_0{}, ans_index_1{};
    for (auto &num : index) {
      if (index.count(target - num.first) > 0) {
        if (num.first == (target - num.first) && lastIndex != -1) {
          ans_index_0 = lastIndex;
          ans_index_1 = num.second;
        } else {
          ans_index_0 = num.second;
          ans_index_1 = index[target - num.first];
        }
      }
      if (ans_index_0 != ans_index_1) {
        break;
      }
    }
    return {ans_index_0, ans_index_1};
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{2, 4, 11, 3};
  std::vector<int> ans = sol.twoSum(nums, 6);
  for (auto &num : ans) {
    std::cout << num << std::endl;
  }
}