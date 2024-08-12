#include <vector>
#include <iostream>
#include <string>
#include <cctype>

//! @brief 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//! 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变
//! 剩余字符相对位置形成的新字符串。
//!（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
//! 
//! @details 
//! 0 <= s.length <= 100
//! 0 <= t.length <= 10^4
//! 两个字符串都只由小写字符组成。
//! ❗
//! 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，
//! 你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
//! 
//! @example 
//! input:  s = "abc", t = "ahbgdc"
//! output: true
//! input:  s = "axc", t = "ahbgdc"
//! output: false
//! 
//! @note
//! 
class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    int tSize = t.size();
    int sIdx = 0, tIdx = 0;
    for (; tIdx < tSize; ++tIdx) {
      if (s[sIdx] == t[tIdx])
        sIdx += 1;
    }
    return sIdx == s.size();
  }
};

int main() {
  Solution sol;
  auto ans = sol.isSubsequence("abc", "ahbgdc");

  std::cout << ans << std::endl;
}
