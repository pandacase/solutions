#include <string>
#include <stack>
#include <iostream>
#include <cctype>
#include <unordered_map>
#include <stdexcept>

//! @brief 
//! 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//! 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
//! 
//! @details 
//! 1 <= s.length <= 3 * 10^5
//! s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
//! s 表示一个有效的表达式
//! '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
//! '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
//! 输入中不存在两个连续的操作符
//! 每个数字和运行的计算将适合于一个有符号的 32位 整数
//! 
//! @example 
//! input:  s = "1 + 1"
//! output: 2
//! 
//! input:  "(1+(4+5+2)-3) + (6+8)"
//! output: 23
//! 
//! @note
//! 中缀直接计算结果：使用 操作符栈 + 操作数栈
//! 1. digit / '(' 直接放入
//! 2. ')' 取出 -> 运算 -> 放入结果 直到遇到 '(' 为止
//! 3. 操作符：更大的优先级则放入，否则取出运算当前栈顶
//! 👆 但是这个暂时不兼容一元运算符 '-' ...吗？
//! 
//! 本题只有 + 和 - 可以考虑更简单的方法...
//! 栈只维护当前正负号，初始栈顶是 1，后续在进入 () 时
//! 压入当前符号。
//! 
class Solution {
public:
  int 
  calculate(std::string s) 
  {
    std::stack<int> ops;
    ops.push(1);
    
    size_t n = s.size();
    int ans = 0, sign = 1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') continue;
      if (std::isdigit(s[i])) {
        long long num = 0;
        while (i < n && std::isdigit(s[i])) {
          num = num * 10 + s[i] - '0';
          ++i;
        }
        ans += sign * num;
        --i;
      } else if (s[i] == '+') {
        sign = ops.top();
      } else if (s[i] == '-') {
        sign = -ops.top();
      } else if (s[i] == '(') {
        ops.push(sign);
      } else if (s[i] == ')') {
        ops.pop();
      }
    }
    return ans;
  }
};
// class Solution {
// public:
//   int 
//   calculate(std::string s) 
//   {
//     std::stack<int> vals;
//     std::stack<char> ops;

//     int n = s.size();
//     for (int i = 0; i < n; ++i) {
//       if (s[i] == ' ') continue;

//       if (std::isdigit(s[i])) {
//         int val = 0;
//         while (i < n && std::isdigit(s[i])) {
//           val = val * 10 + (s[i] - '0');
//           ++i;
//         }
//         vals.push(val);
//         --i;
//       } else if (s[i] == '(') {
//         ops.push(s[i]);
//       } else if (s[i] == ')') {
//         while (!ops.empty() && ops.top() != '(')
//           popAndCompute(vals, ops);
//         if (!ops.empty()) 
//           ops.pop();
//       } else if (_ops_priority.count(s[i])) {
//         if (!ops.empty() && _ops_priority[ops.top()] >= _ops_priority[s[i]])
//           popAndCompute(vals, ops);
//         ops.push(s[i]);
//       } else {
//         throw std::invalid_argument(std::string("Unrecognized character: ") + s[i]);
//       }
//     }

//     while (!ops.empty()) {
//       popAndCompute(vals, ops);
//     }

//     return vals.top();
//   }

// private:
//   void
//   popAndCompute(std::stack<int>& vals, std::stack<char>& ops)
//   {
//     auto val2 = vals.top(); vals.pop();
//     auto val1 = vals.top(); vals.pop();
//     char op = ops.top(); ops.pop();
//     vals.push(applyOp(op, val1, val2));
//   }

//   int
//   applyOp(char op, int val1, int val2) 
//   {
//     if (!_ops_priority.count(op))
//       throw std::invalid_argument(std::string("Unrecognized character: ") + op);
//     else switch (op) {
//       case '+': return val1 + val2;
//       case '-': return val1 - val2;
//       case '*': return val1 * val2;
//       case '/': return val1 / val2;
//       default:  return 0;
//     }
//   }

// private:
//   std::unordered_map<char, size_t> _ops_priority {
//     {'+', 1}, {'-', 1},
//     {'*', 2}, {'/', 2}
//   };
// };

int main() {
  Solution sol;

  auto ans = sol.calculate("(1+(4+5+2)-3) + (6+8)");

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
