#include <vector>
#include <iostream>
#include <string>

//! @brief 编写一个函数来查找字符串数组中的最长公共前缀。
//! 如果不存在公共前缀，返回空字符串 ""。
//! 
//! @details 
//! 1 <= strs.length <= 200
//! 0 <= strs[i].length <= 200
//! strs[i] 仅由小写英文字母组成
//! 
//! @example 
//! input:  strs = ["flower","flow","flight"]
//! output: "fl"
//! input:  strs = ["dog","racecar","car"]
//! output: ""
//! 
//! @note
//! 使用了纵向扫描方法
class Solution {
public:
    std::string 
    longestCommonPrefix(std::vector<std::string>& strs) {
      int size = strs.size();
      int sIdx = 0;
      for (; true; ++sIdx) {
        char firstChar;
        for (int vIdx = 0; vIdx < size; ++vIdx) {
          if (sIdx == strs[vIdx].size()) 
            goto end;
          if (vIdx == 0)
            firstChar = strs[0][sIdx];
          if (strs[vIdx][sIdx] != firstChar)
            goto end;
        }
      }
      end:
      return std::string(strs[0].begin(), strs[0].begin() + sIdx);
    }
};

int main() {
  Solution sol;
  std::vector<std::string> input = {"dog","racecar","car"};
  auto ans = sol.longestCommonPrefix(input);

  std::cout << ans << std::endl;
}
