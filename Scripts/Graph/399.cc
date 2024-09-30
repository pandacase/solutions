
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

//! @brief 
//! 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
//! 其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i]。
//! 每个 Ai 或 Bi 是一个表示单个变量的字符串。
//! 
//! 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，
//! 请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
//! 
//! 返回所有问题的答案。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
//! 如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。
//! 
//! 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，
//! 且不存在任何矛盾的结果。
//! 
//! 注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。
//! 
//! @details 
//! 1 <= equations.length <= 20
//! equations[i].length == 2
//! 1 <= Ai.length, Bi.length <= 5
//! values.length == equations.length
//! 0.0 < values[i] <= 20.0
//! 1 <= queries.length <= 20
//! queries[i].length == 2
//! 1 <= Cj.length, Dj.length <= 5
//! Ai, Bi, Cj, Dj 由小写英文字母与数字组成
//! 
//! @example 
//! input: equations = [["a","b"],["b","c"]], 
//!        values = [2.0,3.0], 
//!        queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
//! output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
//! 解释：条件：a / b = 2.0, b / c = 3.0
//! 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//! 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
//! 注意：x 是未定义的 => -1.0
//! 
//! input: equations = [["a","b"],["b","c"],["bc","cd"]],
//!        values = [1.5,2.5,5.0], 
//!        queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//! output: [3.75000,0.40000,5.00000,0.20000]
//! 
//! input: equations = [["a","b"]], 
//!        values = [0.5], 
//!        queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
//! output: [0.50000,2.00000,-1.00000,-1.00000]
//! 
//! @note
//! 这道题居然可以用并查集。。。待实现中。。。//TODO
//!
class Solution {
public:
  std::vector<double> 
  calcEquation(
    std::vector<std::vector<std::string>>& equations, 
    std::vector<double>& values, 
    std::vector<std::vector<std::string>>& queries) 
  {
    size_t n = values.size();
    // size_t boundary = n * (n - 1) / 2;
    
    _adj.clear();
    for (int i = 0; i < n; ++i) {
      _adj[equations[i][0]].emplace_back(equations[i][1], values[i]);
      _adj[equations[i][1]].emplace_back(equations[i][0], 1 / values[i]);
    }

    std::vector<double> ans;
    for (auto& query : queries) {
      double res = ansState::unset;
      if (!_adj.count(query[0]) || !_adj.count(query[1]))
        res = ansState::invalid;
      else if (query[0] == query[1])
        res = ansState::equivalent;
      else {
        this->dfs(query[0], query[1], res);
        if (res == ansState::unset)
          res = ansState::invalid;
      }
      ans.push_back(res);
    }
    return ans;
  }

private:
  void
  dfs(std::string& begin, std::string& end, double& res)
  {
    std::unordered_set<std::string> visited;
    this->dfs(begin, end, 1, res, visited);
  }

  void
  dfs(std::string& curr, std::string& end,
      double currRes, double& res,
      std::unordered_set<std::string>& visited)
  {
    if (res != ansState::unset) return;
    if (curr == end) {
      res = currRes;
      return;
    }
    visited.insert(curr);
    for (auto& [des, dist] : _adj[curr]) {
      if (!visited.count(des))
        dfs(des, end, currRes * dist, res, visited);
    }
  }

private:
  std::unordered_map<
    std::string, 
    std::vector<std::pair<std::string, double>>
  > _adj;

  enum ansState {
    invalid = -1,
    unset = 0,
    equivalent = 1
  };
};