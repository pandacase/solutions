#include <vector>
#include <iostream>

//! @brief 给你一个数组 nums 和一个值 val，你需要原地移除
//! 所有数值等于 val 的元素。元素的顺序可能发生改变。
//! 然后返回 nums 中与 val 不同的元素的数量。
//! 
//! @details
//! 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要:
//! 更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。
//! nums 的其余元素和 nums 的大小并不重要。
//! 
//! @example 
//! input:  nums = [3,2,2,3], val = 3
//! output: 2, nums = [2,2,_,_]
//! 
//! @note 无
class Solution {
public:
  // int removeElement(std::vector<int>& nums, int val) {
  //   if (nums.size() == 0) return 0;

  //   int nonValCnt = 0;
  //   for (auto &num : nums) {
  //     if (num != val) {
  //       nonValCnt++;
  //     }
  //   }

  //   auto forwardIt = nums.begin();
  //   auto backwordIt = nums.end() - 1;
  //   for (int i = 0; i < nonValCnt; ++i) {
  //     while (*backwordIt == val)
  //       backwordIt--;

  //     // now *backwordIt != val
  //     if (*forwardIt == val) {
  //       *forwardIt = *backwordIt--;
  //     }

  //     forwardIt++;
  //   }

  //   return nonValCnt;
  // }

  int removeElement(std::vector<int>& nums, int val) {
    auto leftIt = nums.begin();
    auto rightIt = nums.begin();
    int nonValCnt = 0;

    for (; rightIt != nums.end(); rightIt++) {
      if (*rightIt != val) {
        *leftIt++ = *rightIt;
        nonValCnt++;
      }
    }

    return nonValCnt;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums{3,2,2,3};
  int val = 3;
  int ans = sol.removeElement(nums, val);

  for (auto it = nums.begin(); it != nums.begin() + ans; it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}