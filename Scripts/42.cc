#include <vector>
#include <iostream>
#include <numeric>

//! @brief 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
//! 计算按此排列的柱子，下雨之后能接多少雨水。
//!
//! @details
//! n == height.length
//! 1 <= n <= 2 * 104
//! 0 <= height[i] <= 105
//! 
//! @example 
//! input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
//! output: 6
//! input:  height = [4,2,0,3,2,5]
//! output: 9
//!  
//! @note
//! 遍历两遍分别获得每个柱子的左侧最高高度和右侧最高高度。
//! 然后就可以计算当前柱子的储水量。
//! （由于第一个柱子和最后一个柱子无论什么情况都无法接到雨水，所以忽略不计）
class Solution {
public:
  int trap(std::vector<int>& height) {
    int size = height.size();

    int max = 0;
    std::vector<int> leftMax(size);
    for (int i = 0; i < size; ++i) {
      max = std::max(max, height[i]);
      leftMax[i] = max;
    }
    
    max = 0;
    std::vector<int> rightMax(size);
    for (int i = size- 1; i >= 0; --i) {
      max = std::max(max, height[i]);
      rightMax[i] = max;
    }

    int water = 0;
    for (int i = 1; i < size - 1; ++i) {
      int lowerHeight = std::min(leftMax[i], rightMax[i]);
      if (lowerHeight > height[i])
        water += lowerHeight - height[i];
    }

    return water;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
  int ans = sol.trap(nums);

  std::cout << ans << std::endl;
}
