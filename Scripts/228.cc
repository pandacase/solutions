#include <string>
#include <stack>
#include <iostream>
#include <vector>

//! @brief 
//! 给定一个 无重复元素 的 有序 整数数组 nums 。
//! 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
//! 也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，
//! 并且不存在属于某个范围但不属于 nums 的数字 x 。
//! 列表中的每个区间范围 [a,b] 应该按如下格式输出：
//!     "a->b" ，如果 a != b
//!     "a" ，如果 a == b
//! 
//! @details 
//! 0 <= nums.length <= 20
//! -231 <= nums[i] <= 231 - 1
//! nums 中的所有值都 互不相同
//! nums 按升序排列
//! 
//! @example 
//! input:  nums = [0,1,2,4,5,7]
//! output: ["0->2","4->5","7"]
//! 
//! input:  nums = [0,2,3,4,6,8,9]
//! output: ["0","2->4","6","8->9"]
//! 
//! @note
//! 
class Solution {
public:
  std::vector<std::string> 
  summaryRanges(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<std::string> ans;
    bool inSegment = false;
    for (int i = 0; i < size; ++i) {
      if (i < size - 1 &&(nums[i + 1] == nums[i] + 1)) {
        if (!inSegment) {
          ans.push_back(std::to_string(nums[i]));
          ans.back().append("->");
          inSegment = true;
        }
      } else {
        if (inSegment) {
          ans.back().append(std::to_string(nums[i]));
          inSegment = false;
        } else {
          ans.push_back(std::to_string(nums[i]));
        }
      }
    }
    return ans;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{0,2,3,4,6,8,9};
  auto ans = sol.summaryRanges(nums);

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  for (auto & a : ans)
    std::cout << a << " ";
  std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
