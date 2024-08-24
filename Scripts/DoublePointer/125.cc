#include <vector>
#include <iostream>
#include <string>
#include <cctype>

//! @brief 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，
//! 短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//! 字母和数字都属于字母数字字符。
//! 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
//! 
//! @details 
//! 1 <= s.length <= 2 * 105
//! s 仅由可打印的 ASCII 字符组成
//! 
//! @example 
//! input:  s = "A man, a plan, a canal: Panama"
//! output: true
//! "amanaplanacanalpanama" 是回文串。
//! input:  s = "race a car"
//! output: false
//! input:  s = " "
//! output: true
//! 
//! @note
//! 
class Solution {
public:
  bool isPalindrome(std::string s) {
    std::string alnumStr;
    for (auto & ch : s) {
      if (std::isalnum(ch))
        alnumStr.push_back(std::tolower(ch));
    }
    return alnumStr == std::string(alnumStr.rbegin(), alnumStr.rend());
  }
};

int main() {
  Solution sol;
  auto ans = sol.isPalindrome("A man, a plan, a canal: Panama");

  std::cout << ans << std::endl;
}
