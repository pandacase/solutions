#include <unordered_set>
#include <vector>
#include <iostream>

//! @brief 
//! 给定一个未排序的整数数组 nums ，找出数字连续的最长序列
//! （不要求序列元素在原数组中连续）的长度。
//! 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
//! 
//! @details 
//! 0 <= nums.length <= 105
//! -109 <= nums[i] <= 109
//! 
//! @example 
//! input:  nums = [100,4,200,1,3,2]
//! output: 4
//! 最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
//! 
//! input:  nums = [0,3,7,2,5,8,4,6,0,1]
//! output: 9
//! 
//! @note
//!
class Solution {
public:
    int 
    longestConsecutive(std::vector<int>& nums) 
    {
      std::unordered_set<int> set(
        nums.begin(), nums.end());

      int ans = 0;
      for (auto& num : set) {
        if (!set.count(num - 1)) {
          int length = 1;
          int currNum = num;
          while (set.count(++currNum))
            length += 1;
          ans = std::max(ans, length);
        }
      }
      return ans;
    }

    // int 
    // longestConsecutive(std::vector<int>& nums) 
    // {
    //   std::unordered_set<int> set(
    //     nums.begin(), nums.end());

    //   int ans = 0;
    //   std::unordered_set<int> seenNum;
    //   for (auto& num : set) {
    //     if (seenNum.count(num) == 0) {
    //       seenNum.insert(num);

    //       int length = 1, currNum = num;
    //       while (set.count(--currNum)) {
    //         length += 1;
    //         seenNum.insert(currNum);
    //       }
    //       currNum = num;
    //       while (set.count(++currNum)) {
    //         length += 1;
    //         seenNum.insert(currNum);
    //       }

    //       ans = std::max(ans, length);
    //     }
    //   }
    //   return ans;
    // }
};

int main() {
  Solution sol;
  std::vector<int> nums{0,3,7,2,5,8,4,6,0,1};
  auto ans = sol.longestConsecutive(nums);

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
