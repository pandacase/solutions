#include <string>
#include <stack>
#include <iostream>
#include <unordered_set>
#include <vector>

//! @brief 
//! 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 
//! 表示的算术表达式。
//! 请你计算该表达式。返回一个表示表达式值的整数。
//! 注意：
//! 有效的算符为 '+'、'-'、'*' 和 '/' 。
//! 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
//! 两个整数之间的除法总是 向零截断 。
//! 表达式中不含除零运算。
//! 输入是一个根据逆波兰表示法表示的算术表达式。
//! 答案及所有中间计算结果可以用 32 位 整数表示。
//! 
//! 逆波兰表达式：
//! 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
//! 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
//! 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
//! 逆波兰表达式主要有以下两个优点：
//! 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据
//! 次序计算出正确结果。
//! 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进
//! 行计算，并将结果压入栈中
//! 
//! @details 
//! 1 <= tokens.length <= 10^4
//! tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），
//! 或是在范围 [-200, 200] 内的一个整数
//! 
//! @example 
//! input:  tokens = ["2","1","+","3","*"]
//! output: 9
//! 该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
//! 
//! input:  tokens = ["4","13","5","/","+"]
//! output: 6
//! 该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
//! 
//! input:  tokens = ["10","6","9","3","+","-11","*","/",
//!                   "*","17","+","5","+"]
//! output: 22
//! 该算式转化为 ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//! 
//! @note
//! 
class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> res;
    std::unordered_set<std::string> ops{
      "+", "-", "*", "/"};
    for (auto& token : tokens) {
      if (ops.count(token)) {
        int op1 = res.top(); res.pop();
        int op2 = res.top(); res.pop();
        if      (token == "+")
          res.push(op2 + op1);
        else if (token == "-")
          res.push(op2 - op1);
        else if (token == "*")
          res.push(op2 * op1);
        else if (token == "/")
          res.push(op2 / op1);
      } else res.push(std::stoi(token));
    }
    return res.top();
  }
};


int main() {
  Solution sol;
  std::vector<std::string> vec{
    "4","13","5","/","+"};
  auto ans = sol.evalRPN(vec);

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
