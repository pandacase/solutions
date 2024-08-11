#include <vector>
#include <iostream>
#include <string>

//! @brief 将一个给定字符串s根据给定的行数numRows，以从上往下、从左到右进行 ᴎ 字形排列。
//! 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//! P   A   H   N
//! A P L S I I G
//! Y   I   R
//! 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//! 
//! @details 
//! 1 <= s.length <= 1000
//! s 由英文字母（小写和大写）、',' 和 '.' 组成
//! 1 <= numRows <= 1000
//! 
//! @example 
//! input:  s = "PAYPALISHIRING", numRows = 3
//! output: "PAHNAPLSIIGYIR"
//! input:  s = "PAYPALISHIRING", numRows = 4
//! output: "PINALSIGYAHRPI"
//! input:  s = "A", numRows = 1
//! output: "A"
//! 
//! @note
//! 
class Solution {
public:
  std::string convert(std::string s, int numRows) {

  }
};

int main() {
  Solution sol;
  auto ans = sol.convert("PAYPALISHIRING", 3);

  std::cout << ans << std::endl;
}
