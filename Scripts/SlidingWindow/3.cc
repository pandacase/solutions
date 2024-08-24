#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

//! @brief 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
//! 
//! @details 
//! 0 <= s.length <= 5 * 104
//! s 由英文字母、数字、符号和空格组成
//! 
//! @example 
//! input:  s = "abcabcbb"
//! output: 3 
//! input:  s = "bbbbb"
//! output: 1
//! input:  s = "pwwkew"
//! output: 3
//! 
//! @note
//! 
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int size = s.size();
    std::unordered_map<char, int> map;
    int maxLength = 0, left = 0, right = 0;
    while (left <= right && right < size) {
      char ch = s[right];
      if (map.count(ch) == 0) {
        map[ch] = right;
        right += 1;
        maxLength = std::max(maxLength, right - left);
      } else {
        int oldLeft = left;
        left = map[ch] + 1;
        for (int i = oldLeft; i < left; ++i)
          map.erase(s[i]);
        map[ch] = right;
        right += 1;
      }
    }
    return maxLength;
  }
};

int main() {
  Solution sol;
  auto ans = sol.lengthOfLongestSubstring("pwwkew");
  
  std::cout << ans << std::endl;
}
