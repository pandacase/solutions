#include <stack>
#include <vector>
#include <iostream>

//! @brief 
//! 设计一个支持push，pop，top操作，并能在O(1)时间检索到最小元素的栈。
//! 实现 MinStack 类:
//! MinStack() 初始化堆栈对象。
//! void push(int val) 将元素val推入堆栈。
//! void pop() 删除堆栈顶部的元素。
//! int top() 获取堆栈顶部的元素。
//! int getMin() 获取堆栈中的最小元素。
//! 
//! @details 
//! -2^31 <= val <= 2^31 - 1
//! pop、top 和 getMin 操作总是在 非空栈 上调用
//! push, pop, top, and getMin 最多被调用 3 * 10^4 次
//! 
//! @example 
//! MinStack minStack = new MinStack();
//! minStack.push(-2);
//! minStack.push(0);
//! minStack.push(-3);
//! minStack.getMin();   --> 返回 -3.
//! minStack.pop();
//! minStack.top();      --> 返回 0.
//! minStack.getMin();   --> 返回 -2.
//! 
//! @note
//! 
class MinStack {
private:
  std::stack<int> nums;
  std::stack<int> mins;

public:
    MinStack() { }
    
    void push(int val) {
      if (!nums.size() || val <= mins.top())
        mins.push(val);
      nums.push(val);
    }
    
    void pop() {
      if (!nums.size()) return;
      if (nums.top() == mins.top())
        mins.pop();
      nums.pop();
    }
    
    int top() {
      return nums.top();
    }
    
    int getMin() {
      return mins.top();
    }
};



int main() {
  auto obj = new MinStack();
  
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  std::cout << obj->getMin() << std::endl;
  obj->pop();
  std::cout << obj->top() << std::endl;
  std::cout << obj->getMin() << std::endl;
}
