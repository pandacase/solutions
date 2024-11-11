

#include <iostream>
#include <vector>
#include <string>

//! @brief 
//! 给定一个不含重复数字的数组 nums，返回其所有可能的全排列。
//! 你可以按任意顺序返回答案。
//! 
//! @details 
//! 1 <= nums.length <= 6
//! -10 <= nums[i] <= 10
//! nums 中的所有整数互不相同。
//! 
//! @example 
//! input: nums = [1,2,3]
//! output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//! 
//! input: nums = [0,1]
//! output: [[0,1],[1,0]]
//! 
//! input: nums = [1]
//! output: [[1]]
//! 
//! @note
//! 
class Solution {
public:
  std::vector<std::vector<int>> 
  permute(std::vector<int>& nums) 
  {
    if (nums.empty()) return {};
    std::vector<std::vector<int>> ans;
    traverse(0, nums, ans);
    return ans;
  }

private:
  void
  traverse(
    size_t idx,
    std::vector<int>& curr_ans,
    std::vector<std::vector<int>>& ans
  ) {
    if (idx == curr_ans.size()) {
      ans.push_back(curr_ans);
      return;
    }

    size_t n = curr_ans.size();
    for (size_t i = idx; i < n; ++i) {
      std::swap(curr_ans[idx], curr_ans[i]);
      traverse(idx + 1, curr_ans, ans);
      std::swap(curr_ans[idx], curr_ans[i]);
    }
  }
};

int 
main()
{
  std::vector<int> nums{1, 2, 3};
  Solution sol;
  sol.permute(nums);
  return 0;
}
