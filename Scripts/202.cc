#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

//! @brief 
//! 编写一个算法来判断一个数 n 是不是快乐数。
//! 「快乐数」 定义为：
//! 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//! 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//! 如果这个过程 结果为 1，那么这个数就是快乐数。
//! 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//! 
//! @details 
//! 1 <= n <= 2^31 - 1
//! 
//! @example 
//! input:  n = 19
//! output: true
//! 1^2 + 9^2 = 82
//! 8^2 + 2^2 = 68
//! 6^2 + 8^2 = 100
//! 1^2 + 0^2 + 0^2 = 1
//! 
//! input:  strs = [""]
//! output: [[""]]
//! 
//! input:  strs = ["a"]
//! output: [["a"]]
//! 
//! @note
//!
class Solution {
public:
  std::vector<std::vector<std::string>> 
  groupAnagrams(std::vector<std::string>& strs) 
  {
    std::unordered_map<std::string, int> word2ansIdx;
    std::vector<std::vector<std::string>> ans;

    for (std::string& str : strs) {
      std::string key = str;
      std::sort(key.begin(), key.end());

      if (word2ansIdx.count(key) == 0) {
        word2ansIdx[key] = ans.size();
        ans.push_back({str, });
      } else {
        ans[word2ansIdx[key]].push_back(str);
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<std::string> strs{
    "eat", "tea", "tan", "ate", "nat", "bat"};
  auto ans = sol.groupAnagrams(strs);

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  for (auto & vec : ans) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}
