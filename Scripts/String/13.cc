#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

//! @brief 给定一个罗马数字，将其转换成整数。
//! 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//! 字符          数值
//! I             1
//! V             5
//! X             10
//! L             50
//! C             100
//! D             500
//! M             1000
//! 例如，罗马数字 2 写做 II ，即为两个并列的 1;
//!      12 写做 XII ，即为 X + II; 
//!      27 写做 XXVII, 即为 XX + V + II。
//! 通常情况下，罗马数字中小的数字在大的数字的右边。
//! 但也存在特例，例如 4 不写做 IIII，而是 IV。
//! 数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4。
//!
//! 同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况:
//! I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//! X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//! C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//! 
//! @details
//! 1 <= s.length <= 15
//! s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
//! 题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
//! 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
//! IL和IM这样的例子并不符合题目要求，49应该写作XLIX，999应该写作CMXCIX。
//! 
//! @example 
//! input:  s = "III"
//! output: 3
//! input:  s = "IX"
//! output: 9
//! input:  s = "LVIII"
//! output: 58 (L = 50, V= 5, III = 3)
//! input:  s = "MCMXCIV" 
//! output: 1994 (M = 1000, CM = 900, XC = 90, IV = 4)
//!
class Solution {
private:
  std::unordered_map<char, int> alphabet = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

public:
  int romanToInt(std::string s) {
    int size = s.size();
    int intRes = 0;
    for (int i = 0; i < size; ++i) {
      if (i + 1 < size && alphabet[s[i]] < alphabet[s[i+1]])
        intRes -= alphabet[s[i]];
      else intRes += alphabet[s[i]];
    }
    return intRes;
  }
};

int main() {
  Solution sol;
  std::string roman("MCMXCIV");
  int ans = sol.romanToInt(roman);

  std::cout << ans << std::endl;
}
