
#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>

//! @brief 
//! 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
//! 如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
//! 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//! 
//! @details 
//! 1 <= s.length <= 300
//! 1 <= wordDict.length <= 1000
//! 1 <= wordDict[i].length <= 20
//! s 和 wordDict[i] 仅由小写英文字母组成
//! wordDict 中的所有字符串 互不相同
//!
//! @example
//! inputs: s = "leetcode", wordDict = ["leet", "code"]
//! output: true
//! 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
//! 
//! inputs: s = "applepenapple", wordDict = ["apple", "pen"]
//! output: true
//! 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//! 注意，你可以重复使用字典中的单词。
//! 
//! @note
//! 这题需要使用 dp 是因为，如果字典里面有 "case" 和 "pencilcase" 且都能匹配
//! 那么从后往前删词的时候就会有状态分叉，而 dp 就是为了消除分叉而来的
//!（本质上是合并中间相同情况，空间换时间）
//!
class Solution {
public:
  bool 
  wordBreak(std::string s, std::vector<std::string>& wordDict) 
  {
    std::unordered_set<std::string> word_dict_set;
    for (auto& word : wordDict) {
      word_dict_set.insert(word);
    }

    size_t n = s.size();
    std::vector<bool> dp(n + 1);
    dp[0] = true;
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (dp[j] && word_dict_set.count(s.substr(j, i-j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};


int main() {

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
