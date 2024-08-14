#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

//! @brief 
//! 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//! ❗若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//! 
//! @details 
//! 1 <= s.length, t.length <= 5 * 10e4
//! s 和 t 仅包含小写字母
//! 
//! @example 
//! input:  s = "anagram", t = "nagaram"
//! output: true
//! 
//! input:  ps = "rat", t = "car"
//! output: false
//! 
//! @note
//! ⚠️ 如果输入字符串包含 unicode 字符怎么办？
//! 你能否调整你的解法来应对这种情况？
//! 💡 对于 c++ 来说需要启用 std::u32string；
//! ⭐ BMP（Basic Multilingual Plane，基本多语言平面）是 Unicode 
//! 标准中的第一个平面，范围从 U+0000 到 U+FFFF。
class Solution {
public:
  bool 
  isAnagram(std::string s, std::string t) 
  {
    if (s.size() != t.size()) return false;
    bool ans = true;
    std::unordered_map<char, int> counter;
    for (auto & ch : s) 
      counter[ch] += 1;
    for (auto & ch : t) {
      counter[ch] -= 1;
      // 由于一开始长度不相同已经返回错误了，所以如果在完全遍历之后
      // 若有 counter[ch] 是 > 0 的，则必然存在另一个值 < 0
      if (counter[ch] < 0) {
        ans = false;
        break;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  auto ans = sol.isAnagram("anagram", "nagaram");
  
  std::cout << ans << std::endl;
}
