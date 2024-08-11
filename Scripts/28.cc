#include <vector>
#include <iostream>
#include <string>

//! @brief 给你两个字符串 haystack 和 needle ，请你在 haystack 
//! 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//! 如果 needle 不是 haystack 的一部分，则返回  -1 。
//! 
//! @details 
//! 1 <= haystack.length, needle.length <= 104
//! haystack 和 needle 仅由小写英文字符组成
//! 
//! @example 
//! input:  haystack = "sadbutsad", needle = "sad"
//! output: 0
//! "sad" 在下标 0 和 6 处匹配。第一个匹配项的下标是 0 ，所以返回 0。
//! input:  haystack = "leetcode", needle = "leeto"
//! output: -1
//! "leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
//! 
//! @note
//! 
class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    int size = haystack.size();
    
    int ans = -1;
    for (int i = 0; i < size; ++i) {
      if (haystack[i] == needle[0]) {
        int needleSize = needle.size();
        if (haystack.compare(i, needleSize, needle) == 0) {
          ans = i;
          break;
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  auto ans = sol.strStr("hello", "ll");

  std::cout << ans << std::endl;
}
