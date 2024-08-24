#include <vector>
#include <iostream>
#include <string>

//! @brief 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。
//! 返回字符串中 最后一个单词的长度。
//! 
//! @details 
//! 1 <= s.length <= 10^4
//! s 仅有英文字母和空格 ' ' 组成
//! s 中至少存在一个单词
class Solution {
public:
    int lengthOfLastWord(std::string s) {
      int size = s.size();
      
      int lengthRes = 0;
      bool getWord = false;
      for (int i = size - 1; i >= 0; --i) {
        if (!getWord && s[i] != ' ') 
          getWord = true;
        
        if (getWord) {
          if (s[i] != ' ') lengthRes += 1;
          else break;
        }
      }

      return lengthRes;
    }
};

int main() {
  Solution sol;
  auto ans = sol.lengthOfLastWord("hello world");

  std::cout << ans << std::endl;
}
