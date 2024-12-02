
#include <iostream>
#include <vector>
#include <string>

//! @brief 
//! 数字 n 代表生成括号的对数，请你设计一个函数，
//! 用于生成所有可能的并且有效的括号组合。
//! 
//! @details 
//! 1 <= n <= 8
//! 
//! @example 
//! input: n = 3
//! output: ["((()))","(()())","(())()","()(())","()()()"]
//! 
//! input: n = 1
//! output: ["()"]
//!
//! @note 
//! 剩余左括号总数要小于等于右括号
//! 
class Solution {
public:
  std::vector<std::string> 
  generateParenthesis(int n) 
  {
    std::vector<std::string> ans{};
    std::string curr_ans{};
    dfs(n, n, curr_ans, ans);
    return ans;
  }

private:
  void
  dfs(
    int left,
    int right,
    std::string& curr_ans,
    std::vector<std::string>& ans
  ) {
    if (left == 0 && right == 0) {
      ans.push_back(curr_ans);
      return;
    }

    if (left > 0) {
      curr_ans.push_back('(');
      dfs(left - 1, right, curr_ans, ans);
      curr_ans.pop_back();
    }

    if (left < right) {
      curr_ans.push_back(')');
      dfs(left, right - 1, curr_ans, ans);
      curr_ans.pop_back();
    }
  }
};
