#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

//! @brief 
//! 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，
//! 判断一个括号字符串是否有效。
//! 
//! @details 
//! 1 <= s.length <= 10^4
//! s 仅由括号 '()[]{}' 组成
//! 
//! @example 
//! input:  s = "()[]{}"
//! output: true
//! 
//! input:  s = "(]"
//! output: false
//! 
//! @note
//! 
class Solution {
public:
  bool isValid(std::string s) {
    std::unordered_map<char, char> match{
      {')', '('},
      {'}', '{'},
      {']', '['}
    };
    std::stack<char> brackets;
    
    for (auto& ch : s) {
      if (!brackets.empty() && brackets.top() == match[ch])
        brackets.pop();
      else brackets.push(ch);
    }

    return brackets.empty();
  }
};


int main() {
  Solution sol;

  auto ans = sol.isValid("{}[][{()()}][]");

  //! 0  
  std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
