

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
  combine(int n, int k) 
  {
    std::vector<std::vector<int>> ans;
    std::vector<int> curr_combine;
    combine(n, k, 1, curr_combine, ans);
    return ans;
  }

private:
  void
  combine(
    int n, 
    int k,
    size_t curr_idx, 
    std::vector<int>& curr_combine,
    std::vector<std::vector<int>>& ans)
  {
    if (curr_combine.size() == size_t(k)) {
      ans.push_back(curr_combine);
      return;
    }

    for (int i = curr_idx; i <= n; ++i) {
      curr_combine.push_back(i);
      combine(n, k, i + 1, curr_combine, ans);
      curr_combine.pop_back();
    }
  }
};


int 
main()
{
  Solution sol;
  sol.combine(2, 1);
  return 0;
}
