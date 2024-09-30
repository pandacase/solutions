#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 
//! 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
//! 
//! @details 
//! 1 <= a.length, b.length <= 10^4
//! a 和 b 仅由字符 '0' 或 '1' 组成
//! 字符串如果不是 "0" ，就不含前导零
//! 
//! @note
//! //TODO 不定长的 a/b 合并的优雅实现，等有空再写一遍。
//! 另外，使用 x^y 可以模拟加法不进位运算；(x&y)<<1 可以模拟进位结果
//! 
class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string ans;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int n = std::max(a.size(), b.size()), carry = 0;
    for (size_t i = 0; i < n; ++i) {
      carry += i < a.size() ? (a.at(i) == '1') : 0;
      carry += i < b.size() ? (b.at(i) == '1') : 0;
      ans.push_back((carry % 2) ? '1' : '0');
      carry /= 2;
    }

    if (carry) {
      ans.push_back('1');
    }
    std::reverse(ans.begin(), ans.end());

    return ans;
  }
};


int main() {
  Solution sol;

  auto ans = sol.addBinary("11", "1");

  // print link
  std::cout << ans << std::endl;
}
