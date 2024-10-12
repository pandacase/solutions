
#include <iostream>
#include <unordered_map>
#include <deque>
#include <vector>
#include <unordered_set>

class Solution {
private:
  void
  traverse(
    std::vector<int>& ans,
    size_t curr_line,
    std::unordered_map<size_t, size_t>& curr2next,
    std::vector<std::vector<int>>& secret
  ) {
    if (curr_line == 0)
      return;

    auto next_line = curr2next[curr_line];
    traverse(ans, next_line, curr2next, secret);
    ans.push_back(secret[curr_line - 1][0]);
  }

public:
  std::vector<int>
  recover(std::vector<std::vector<int>>& secret)
  {
    size_t n = secret.size();
    std::unordered_set<size_t> seen;
    for (size_t i = 0; i <= n; ++i) {
      seen.insert(i);
    }
    
    std::unordered_map<size_t, size_t> curr2next;
    for (int i = 0; i < n; ++i) {
      auto& pair = secret[i];
      seen.erase(pair[1]);
      curr2next[i + 1] = pair[1];
    }

    std::vector<int> ans;
    traverse(ans, *(seen.begin()), curr2next, secret);
    return ans;
  }
};

int
main()
{
  Solution sol;
  // std::vector<std::vector<int>> secret {
  //   {6, 3},
  //   {9, 4},
  //   {7, 0},
  //   {3, 5},
  //   {2, 1}
  // };
  std::vector<std::vector<int>> secret {
    {2, 2},
    {6, 3},
    {7, 4},
    {2, 5},
    {8, 6},
    {2, 0}
  };

  auto ans = sol.recover(secret);
  for (auto i : ans) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}