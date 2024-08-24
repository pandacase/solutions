#include <vector>
#include <iostream>
#include <string>

//! @brief 给定一个整数，将其转换为罗马数字。
//! 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//! 字符          数值
//! I             1
//! V             5
//! X             10
//! L             50
//! C             100
//! D             500
//! M             1000
//! 罗马数字是通过添加从最高到最低的小数位值的转换而形成的。
//! 将小数位值转换为罗马数字有以下规则：
//! 如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，
//! 将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
//! 如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，
//! 例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。
//! 仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
//! 只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。
//! 你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用减法形式。
//! 
//! @details
//! 1 <= num <= 3999
//! 
//! @example 
//! input:  num = 3749
//! output:  "MMMDCCXLIX"
//! 3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
//!  700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
//!   40 = XL 由于 50 (L) 减 10 (X)
//!    9 = IX 由于 10 (X) 减 1 (I)
//! 注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
//! 
class Solution {
private:
  std::vector<std::pair<std::string, int>> alphabet = {
    {"M", 1000}, 
    {"CM", 900}, 
    {"D", 500}, 
    {"CD", 400}, 
    {"C", 100}, 
    {"XC", 90}, 
    {"L", 50}, 
    {"XL", 40}, 
    {"X", 10}, 
    {"IX", 9},
    {"V", 5}, 
    {"IV", 4}, 
    {"I", 1}, 
  };

public:
  std::string intToRoman(int num) {
    std::string romanRes;
    for (auto &[chara, value] : alphabet) {
      while (num >= value) {
        romanRes += chara;
        num -= value;
      }
    }
    return romanRes;
  }
};

int main() {
  Solution sol;
  auto ans = sol.intToRoman(3749);

  std::cout << ans << std::endl;
}
