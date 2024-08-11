#include <vector>
#include <iostream>
#include <string>

//! @brief 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//! 单词: 由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的单词分隔开。
//! 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
//! 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
//! 返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
//! 
//! @details 
//! 1 <= s.length <= 104
//! s 包含英文大小写字母、数字和空格 ' '
//! s 中 至少存在一个 单词
//! 
//! @example 
//! input:  s = "the sky is blue"
//! output: "blue is sky the"
//! input:  s = "  hello world  "
//! output: "world hello"
//! input:  s = "a good   example"
//! output: "example good a"
//! 
//! @note
//! 
class Solution {
public:
    std::string reverseWords(std::string s) {
      int size = s.size();
      
      std::vector<std::string> words;
      int beginIdx = -1, lengthOfWord = 0;
      for (int i = 0; i < size; ++i) {
        if (((i > 0 &&  s[i-1] == ' ') || i == 0) && s[i] != ' ') {
          beginIdx = i;
        }
        if (beginIdx != -1 && s[i] != ' ') {
          lengthOfWord += 1;
        }
        if (beginIdx != -1 && (s[i] == ' ' || i == size - 1)) {
          auto begin = s.begin() + beginIdx;
          words.push_back(std::string(begin, begin + lengthOfWord));
          beginIdx = -1;
          lengthOfWord = 0;
        }
      }

      s.clear();
      for (int i = words.size() - 1; i >= 0; --i) {
        s.append(words[i]);
        if (i != 0) s.push_back(' ');
      }

      return s;
    }
};

int main() {
  Solution sol;
  auto ans = sol.reverseWords("the sky is blue");

  std::cout << ans << std::endl;
}
