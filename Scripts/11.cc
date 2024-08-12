#include <vector>
#include <iostream>
#include <string>

//! @brief 给定一个长度为 n 的整数数组 height 。
//! 有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
//! 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//! 返回容器可以储存的最大水量(注意：计算的是面积，柱子只有高度没有宽度)。
//! 说明：你不能倾斜容器。
//! 
//! @details 
//! n == height.length
//! 2 <= n <= 10e5
//! 0 <= height[i] <= 10e4
//! 
//! @example 
//! input:  [1,8,6,2,5,4,8,3,7]
//! output: 49 
//! input:  height = [1,1]
//! output: 1
//! 
//! @note
//! 
class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    while (left < right) {
      ans = std::max(
        ans, 
        std::min(height[left], height[right]) * (right - left)
      );
      if (height[left] <= height[right])
        left += 1;
      else
        right -= 1;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<int> height{1,8,6,2,5,4,8,3,7};
  auto ans = sol.maxArea(height);

  std::cout << ans << std::endl;
}
