#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 给你一个非负整数数组 nums ，你最初位于数组的第一个下标。
//! 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//! 判断你是否能够到达最后一个下标，如果可以，返回true；否则，返回false。
//!
//! @details
//! 1 <= nums.length <= 104
//! 0 <= nums[i] <= 105
//! 
//! @example
//! input:  nums = [2,3,1,1,4]
//! output: true
//! 可以先跳1步，从下标0到达下标1, 然后再从下标1跳3步到达最后一个下标。
//! input:  nums = [3,2,1,0,4]
//! output: false
//! 无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0。
//! 
//! @note
//! 追踪当前能达到的最远距离des，如果在到达某个点时后更新的 des 
//! 仍然是他自己，则这个坎就过不去了。
//! 官方题解思路类似，只有 i < des 时才更新 des，到达终点时返回 true，
//! 遍历结束时返回 false。
class Solution {
public:
  bool canJump(std::vector<int>& nums) {
    int size = nums.size();
    int des = 0;
    for (int i = 0; i < size; ++i) {
      des = std::max(des, i + nums[i]);
      if (des == size - 1) return true;
      if (des == i) return false;
    }
    return true;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{2,3,1,1,4};
  bool ans = sol.canJump(nums);

  std::cout << ans << std::endl;
}
