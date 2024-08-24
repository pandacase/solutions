#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

//! @brief 
//! 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
//! 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中
//! 的每个非空单词之间存在着双向连接的对应规律。
//! 
//! @details 
//! 1 <= pattern.length <= 300
//! pattern 只包含小写英文字母
//! 1 <= s.length <= 3000
//! s 只包含小写英文字母和 ' '
//! s 不包含 任何前导或尾随对空格
//! s 中每个单词都被 单个空格 分隔
//! 
//! @example 
//! input:  pattern = "abba", s = "dog cat cat dog"
//! output: true
//!
//! input:  pattern = "abba", s = "dog cat cat fish"
//! output: false
//!
//! input:  pattern = "aaaa", s = "dog cat cat dog"
//! output: false
//! 
//! @note
//! 使用 `istringstream` 与 `>>` 来识别单词
class Solution {
public:
  bool 
  wordPattern(std::string pattern, std::string s) 
  {
    std::vector<std::string> words;
    std::istringstream iss(s);
    std::string word;
    while (iss >> word) {
      words.push_back(word);
    }

    int size = words.size();
    if (size != pattern.size()) return false;

    bool ans = true;
    std::unordered_map<std::string, char> word2char;
    std::unordered_set<char> seenChar;

    for (int i = 0; i < size; ++i) {
      word = words[i];
      if (word2char[word] == 0) {
        word2char[word] = pattern[i];
        if (seenChar.count(pattern[i])) {
          ans = false;
          break;
        } else {
          seenChar.insert(pattern[i]);
        }
      } else if (word2char[word] != pattern[i]) {
        ans = false;
        break;
      }
    }

    return ans;
  }

  // bool 
  // wordPattern(std::string pattern, std::string s) 
  // {
  //   bool ans = true;
  //   std::unordered_map<std::string, char> word2char;
  //   std::unordered_set<char> seenChar;
  //   s.push_back(' ');

  //   int patSize = pattern.size(), sSize = s.size();
  //   bool inWord = false;
  //   int wordBegin = -1, patternIdx = 0;
  //   for (int i = 0; i < sSize; ++i) {
  //     if (!inWord && s[i] != ' ') {
  //       inWord = true;
  //       wordBegin = i;
  //     } else if (inWord && s[i] == ' ') {
  //       // complete reading a new word
  //       if (patternIdx >= patSize) {
  //         ans = false;
  //         break;
  //       }

  //       inWord = false;
  //       std::string word(s.begin() + wordBegin, s.begin() + i);
  //       if (word2char.count(word) == 0) {
  //         word2char[word] = pattern[patternIdx];
  //         if (seenChar.count(pattern[patternIdx]) == 0)
  //           seenChar.insert(pattern[patternIdx]);
  //         else {
  //           ans = false;
  //           break;
  //         }
  //       } else {
  //         if (word2char[word] != pattern[patternIdx]) {
  //           ans = false;
  //           break;
  //         }
  //       }
  //       ++patternIdx;
  //     }

  //   } // end for (int i = 0, j = 0; i < sSize; ++i)

  //   if (patternIdx != patSize)
  //     ans = false;

  //   return ans;
  // }
};

int main() {
  Solution sol;
  auto ans = sol.wordPattern("abba", "dog cat cat dog");
  
  std::cout << ans << std::endl;
}
