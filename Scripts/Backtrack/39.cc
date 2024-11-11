
#include <iostream>
#include <vector>
#include <string>

//! @brief 
//! 给你一个无重复元素的整数数组 candidates 和一个目标整数 target，
//! 找出 candidates 中可以使数字和为目标数 target 的所有不同组合，
//! 并以列表形式返回。你可以按任意顺序返回这些组合。
//! 
//! candidates 中的同一个数字可以无限制重复被选取。如果至少一个数字的
//! 被选数量不同，则两种组合是不同的。
//! 
//! 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//! 
//! @details 
//! 1 <= candidates.length <= 30
//! 2 <= candidates[i] <= 40
//! candidates 的所有元素互不相同
//! 1 <= target <= 40
//! 
//! @example 
//! input: candidates = [2,3,6,7], target = 7
//! output: [[2,2,3],[7]]
//! 解释: 
//! 2 和 3 可以形成一组候选，2 + 2 + 3 = 7。注意 2 可以使用多次。
//! 7 也是一个候选，7 = 7。仅有这两种组合。
//! 
//! input: candidates = [2,3,5], target = 8
//! output: [[2,2,2,2],[2,3,3],[3,5]]
//! 
//! input: candidates = [2], target = 1
//! output: []
//! 
class Solution {
public:
  std::vector<std::vector<int>> 
  combinationSum(std::vector<int>& candidates, int target) 
  {
    std::vector<std::vector<int>> ans;
    std::vector<int> curr_ans;
    combine(candidates, target, 0, 0, curr_ans, ans);
    return ans;
  }

private:
  void
  combine(
    std::vector<int>& candidates,
    int traget,
    int idx,
    int curr_sum,
    std::vector<int>& curr_ans,
    std::vector<std::vector<int>>& ans
  ) {
    if (curr_sum == traget) {
      ans.push_back(curr_ans);
      return;
    } else if (curr_sum > traget) {
      return;
    }
    
    auto n = candidates.size();  
    for (int i = idx; i < n; ++i) {
      auto num = candidates[i];
      curr_ans.push_back(num);
      combine(candidates, traget, i, curr_sum + num, curr_ans, ans);
      curr_ans.pop_back();
    }
  }
};

int 
main()
{
  std::vector<int> nums{2, 3, 6, 7};
  Solution sol;
  sol.combinationSum(nums, 7);
  return 0;
}
