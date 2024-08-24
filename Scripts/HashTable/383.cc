#include <unordered_map>
#include <iostream>
#include <string>

//! @brief 给你两个字符串：ransomNote 和 magazine ，
//! 判断 ransomNote 能不能由 magazine 里面的字符构成。
//! 如果可以，返回 true ；否则返回 false 。
//! 
//! @details 
//! 1 <= ransomNote.length, magazine.length <= 105
//! ransomNote 和 magazine 由小写英文字母组成
//! ❗magazine 中的每个字符只能在 ransomNote 中使用一次。
//! 
//! @example 
//! input:  ransomNote = "a", magazine = "b"
//! output: false
//!
//! input:  ransomNote = "aa", magazine = "ab"
//! output: false
//!
//! input:  ransomNote = "aa", magazine = "aab"
//! output: true
//! 
//! @note
//! 
class Solution {
public:
  bool 
  canConstruct(std::string ransomNote, std::string magazine) 
  {
    std::unordered_map<char, int> counter;
    for (char & ch : magazine)
      counter[ch] += 1;

    bool ans = true;
    for (char & ch : ransomNote) {
      if (counter.count(ch) == 0 || counter[ch] <= 0) {
        ans = false;
        break;
      }
      else {
        counter[ch] -= 1;
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  auto ans = sol.canConstruct("aa", "aab");
  
  std::cout << ans << std::endl;
}
