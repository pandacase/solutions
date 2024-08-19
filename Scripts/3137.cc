#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

//! @brief 
//! 给你一个长度为 n 的字符串 word 和一个整数 k ，其中 k 是 n 的因数。
//! 在一次操作中，你可以选择任意两个下标 i 和 j，其中 0 <= i, j < n ，
//! 且这两个下标都可以被 k 整除，然后用从 j 开始的长度为 k 的子串替换
//! 从 i 开始的长度为 k 的子串。也就是说，将子串 word[i..i + k - 1] 
//! 替换为子串 word[j..j + k - 1] 。
//! 返回使 word 成为 K 周期字符串 所需的 最少 操作次数。
//! 如果存在某个长度为 k 的字符串 s，使得 word 可以表示为任意次数连接 s ，
//! 则称字符串 word 是 K 周期字符串 。例如，如果 word == "ababab"，
//! 那么 word 就是 s = "ab" 时的 2 周期字符串 。
//! 
//! @details 
//! 1 <= n == word.length <= 105
//! 1 <= k <= word.length
//! k 能整除 word.length 。
//! word 仅由小写英文字母组成。
//! 
//! @example 
//! input:  word = "leetcodeleet", k = 4
//! output: 1
//! 可以选择 i = 4 和 j = 0 获得一个 4 周期字符串。这次操作后，
//! word 变为 "leetleetleet" 。
//! 
//! input:  word = "leetcoleet", k = 2
//! output: 3
//! 
//! @note
//! 
class Solution {
public:
  int 
  minimumOperationsToMakeKPeriodic(std::string words, int k) 
  {
    int size = words.size(), nWord = size / k;
    std::unordered_map<std::string, int> wordCnt; 
    int maxCnt = 0;
    for (int i = 0; i < size; i += k) {
      std::string word = words.substr(i, k);
      wordCnt[word] += 1;
      maxCnt = std::max(maxCnt, wordCnt[word]);
    }
    return nWord - maxCnt;
  }
};

int main() {
  Solution sol;
  auto ans 
    = sol.minimumOperationsToMakeKPeriodic("leetcodeleet", 4);

  //! 0  
  std::cout << ans << std::endl;

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
