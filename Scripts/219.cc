#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

//! @brief 
//! 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个
//! 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
//! 如果存在，返回 true ；否则，返回 false 。
//! 
//! @details 
//! 1 <= nums.length <= 105
//! -109 <= nums[i] <= 109
//! 0 <= k <= 105
//! 
//! @example 
//! input:  nums = [1,2,3,1], k = 3
//! output: true
//! 
//! input:  nums = [1,0,1,1], k = 1
//! output: true
//! 
//! input:  nums = [1,2,3,1,2,3], k = 2
//! output: false
//! 
//! @note
//!
class Solution {
public:
  bool 
  containsNearbyDuplicate(std::vector<int>& nums, int k) 
  {
    bool ans = false;
    int size = nums.size();
    std::unordered_map<int, int> index;
    for (int i = 0; i < size; ++i) {
      if (index.count(nums[i]) && i - index[nums[i]] <= k) {
        ans = true;
        break;
      }
      index[nums[i]] = i;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums{1,2,3,1,2,3};
  auto ans = sol.containsNearbyDuplicate(nums, 2);

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
