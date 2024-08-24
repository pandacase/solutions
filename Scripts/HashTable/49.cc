#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

//! @brief 
//! 给你一个字符串数组，请你将 字母异位词 组合在一起。
//! 可以按任意顺序返回结果列表。
//! 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
//! 
//! @details 
//! 1 <= strs.length <= 104
//! 0 <= strs[i].length <= 100
//! strs[i] 仅包含小写字母
//! 
//! @example 
//! input:  strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//! output: [["bat"],["nat","tan"],["ate","eat","tea"]]
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
