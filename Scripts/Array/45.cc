#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

//! @brief 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

//! 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。
//! 换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//! - 0 <= j <= nums[i] 
//! - i + j < n
//! 返回到达 nums[n - 1] 的最小跳跃次数。
//!
//! @details
//! 题目保证可以到达 nums[n-1]
//! 1 <= nums.length <= 104
//! 0 <= nums[i] <= 1000
//! 
//! @example
//! input:  nums = [2,3,1,1,4]
//! output: 2
//! 跳到最后一个位置的最小跳跃数是 2。
//! 从下标为 0 跳到下标为 1 的位置，跳 1 步，
//! 然后跳 3 步到达数组的最后一个位置。
//! input:  nums = [2,3,0,1,4]
//! output: 2
//! 
//! @note
//! 线性遍历的方法：走到当前贪心步骤的边界 end 时，更新为当前记录的 maxPos
class Solution {
public:
  // int jump(std::vector<int>& nums) {
  //   int size = nums.size();
  //   int inf = std::numeric_limits<int>::max();
  //   std::vector<int> minStep(size, inf);
  //   minStep[0] = 0;
  //   for (int i = 0; i < size - 1; ++i) {
  //     int des = i + nums[i];
  //     for (int j = i + 1; j <= des; ++j) {
  //       if (j < size)
  //         minStep[j] = std::min(minStep[j], minStep[i] + 1);
  //     }
  //   }
  //   return minStep[size - 1];
  // }

  int jump(std::vector<int>& nums) {
    int size = nums.size();
    int step = 0, maxPos = 0, end = 0;
    for (int i = 0; i < size - 1; ++i) {
      maxPos = std::max(maxPos, i + nums[i]);
      if (i == end) {
        end = maxPos;
        ++step;
      }
    }
    return step;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{2,3,1,1,4};
  int ans = sol.jump(nums);

  std::cout << ans << std::endl;
}
