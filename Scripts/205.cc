#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

//! @brief 给定两个字符串 s 和 t ，判断它们是否是同构的。
//! 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
//! 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
//! 不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，
//! 字符可以映射到自己本身。
//! 
//! @details 
//! 1 <= s.length <= 5 * 104
//! t.length == s.length
//! s 和 t 由任意有效的 ASCII 字符组成
//! 
//! @example 
//! input:  s = "egg", t = "add"
//! output: true
//!
//! input:  s = "foo", t = "bar"
//! output: false
//!
//! input:  s = "paper", t = "title"
//! output: true
//! 
//! @note
//! 
class Solution {
public:
  bool 
  isIsomorphic(std::string s, std::string t) 
  {
    int size = s.size();
    if (size != t.size()) return false;
    
    bool ans = true;
    std::unordered_map<char, char> charMap;
    std::unordered_set<char> seenChar;

    
    for (int i = 0; i < size; ++i) {
      if (charMap.count(s[i]) == 0) {
        charMap[s[i]] = t[i];
        if (seenChar.count(t[i])) {
          ans = false;
          break;
        } else {
          seenChar.insert(t[i]);
        }
      } else if (charMap[s[i]] != t[i]) {
        ans = false;
        break;
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  auto ans = sol.isIsomorphic("badc", "baba");
  
  std::cout << ans << std::endl;
}