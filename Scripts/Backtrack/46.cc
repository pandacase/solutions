

#include <iostream>
#include <vector>
#include <string>

//! @brief 
//! 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
//! 
//! 你可以按任何顺序返回答案。
//! 
//! @details 
//! 1 <= n <= 20
//! 1 <= k <= n
//! 
//! @example 
//! input: n = 4, k = 2
//! output: 
//! [
//!   [2,4],
//!   [3,4],
//!   [2,3],
//!   [1,2],
//!   [1,3],
//!   [1,4]
//! ]
//! 
//! input: n = 1, k = 1
//! output: [[1]]
//! 
class Solution {
public:
  std::vector<std::vector<int>> 
  permute(std::vector<int>& nums) 
  {
    std::vector<std::vector<int>> ans;
    std::vector<int> curr_ans;
    traverse(nums, ans, 0);
    return ans;
  }

private:
  void
  traverse(
    std::vector<int>& nums,
    std::vector<std::vector<int>>& ans,
    size_t idx
  ) {
    if (idx == nums.size()) {
      ans.push_back(nums);
      return;
    }
    size_t n = nums.size();

    for (size_t i = idx; i < n; ++i) {
      std::swap(nums[i], nums[idx]);
      traverse(nums, ans, idx + 1);
      std::swap(nums[i], nums[idx]);
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
