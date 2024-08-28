
#include <iostream>

//! @brief 
//! 颠倒给定的 32 位无符号整数的二进制位。
//! 
//! @details 
//! 输入是一个长度为 32 的二进制字符串
//! 
//! @example
//! inputs:  n = 43261596 (00000010100101000001111010011100)
//! outputs: 964176192 (00111001011110000010100101000000)
//! 
//! inputs:  n = 4294967293 (11111111111111111111111111111101)
//! outputs: 3221225471 (10111111111111111111111111111111)
//! 
//! @note
//! 
class Solution {
public:
  uint32_t 
  reverseBits(uint32_t n) 
  {
    uint32_t res = 0;
    for (int i = 0; i < 32 && n > 0; ++i) {
      res |= (n & 1) << (31 - i);
      n >>= 1;
    }
    return res;
  }
};



int main() {
  Solution sol;
  auto ans = sol.reverseBits(43261596);

  // print link
  std::cout << ans << std::endl;
}
