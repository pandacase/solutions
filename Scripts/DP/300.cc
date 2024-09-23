
#include <vector>
#include <iostream>
#include <unordered_map>

//! @brief 
//! 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//! 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素
//! 而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 
//! 的子序列。
//! 
//! @details 
//! 1 <= nums.length <= 100
//! 0 <= nums[i] <= 400
//! 
//! @example
//! inputs: nums = [10,9,2,5,3,7,101,18]
//! output: 4
//! 最长递增子序列是 [2,3,7,101]，因此长度为 4 。
//! 
//! inputs: nums = [0,1,0,3,2,3]
//! output: 4
//! 
//! @note
//! 常规动态规划可以在 O(n^2) 时间复杂度下完成
//! 如何降低到 O(nlogn) 呢？
//! 
class Solution {
public:
  // int 
  // lengthOfLIS(std::vector<int>& nums) 
  // {
  //   int n = nums.size();
  //   std::vector<int> dp(n, 1);

  //   int ans = 1;
  //   for (int i = 1; i < n; ++i) {
  //     for (int j = 0; j < i; ++j) {
  //       if (dp[j] >= dp[i] && nums[j] < nums[i]) {
  //         dp[i] = dp[j] + 1;
  //         ans = std::max(ans, dp[i]);
  //       }
  //     }
  //   }

  //   return ans;
  // }

  int 
  lengthOfLIS(std::vector<int>& nums) 
  {
    int n = nums.size();
    //! min_terminal[i] 表示：长度为 i + 1 的递增序列中，
    //! 最后一个元素的最小值
    std::vector<int> min_terminal{nums[0]};

    for (int i = 1; i < n; ++i) {
      if (int num = nums[i]; num > min_terminal.back()) {
        min_terminal.push_back(num);
      } else {
        size_t j = first_greater_equal(min_terminal, num);
        min_terminal[j] = num;
      }
    }

    return min_terminal.size();
  }

private:
  size_t
  first_greater_equal(std::vector<int>& vec, int value) {
    int low = 0, high = vec.size();
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (vec[mid] >= value) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (low < vec.size() && vec[low] >= value) 
      return low;
    else
      return -1;
  }
};

int main() {

  //! 0  
  // std::cout << ans << std::endl;

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
