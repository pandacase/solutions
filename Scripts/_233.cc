#include <iostream>
#include <cmath>
#define DECIMAL 10

//! @brief 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数
//! 
//! @example
//! input:  n = 13
//! output: 6
//!
//! @note
//!
class Solution {
public:
    int countDigitOne(const int n) {
        int ans = 0;
        int bitWidth = 0, msb = 0;
        int number = n;
        while (number) {
            msb = number % 10;
            bitWidth += 1;
            std::cout << msb << ", " << bitWidth << std::endl;
            std::cout << "count(): " << countBase(msb, bitWidth) << std::endl;
            ans += countBase(msb, bitWidth);
            number /= 10;
        }
        return {ans};
    }

// private:
    int countBase(const int msb, const int bitWidth) {
        int ans = 1;
        int packet = 1;
        // 13
        // msb = 1
        // bitWidth = 2
        if (bitWidth == 1) {
            if (msb >= 1) {
                ans = 1;
            } else {
                ans = 0;
            }
        } else {
            for (int i = 1; i < bitWidth; ++i) {
                int base = pow(DECIMAL, i);
                if (i < bitWidth - 1) {
                    ans += (packet * (DECIMAL - 1) + base);
                } else if (i == bitWidth - 1) { // the last cycle
                    if (msb == 1) {

                    } else {
                        for (int i = 1; i < msb; ++i) {
                            if (i == 1) {
                                ans += (packet + base);
                            } else {
                                ans += packet;
                            }
                        }
                    }
                }
                packet = ans;
            }
        }
        
        return {ans};
    }
};


int main() {
    Solution sol;
    // std::cout << sol.countBase(3, 2) << std::endl;
    std::cout << sol.countDigitOne(231) << std::endl;

}


// 12

// 1

// 10 11 12 13 14 15 16 17 18 19
//    21
//    31
//    41
//    51
//    61
//    71
//    81
//    91



// 1.. packet_2 + 10**2
// 2.. packet_2
// 3.. packet_2
// 4.. ...

// 432

// 32
// 