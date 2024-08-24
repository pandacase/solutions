#include <vector>
#include <iostream>

//! @brief 给你两个按非递减顺序排列的整数数组 nums1 和 nums2，
//! 另有两个整数 m 和 n，分别表示 nums1 和 nums2 中的元素数目。
//! 请你合并 nums2 到 nums1 中，使合并后的数组同样按非递减顺序排列。
//!
//! @details
//! 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//! 为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示
//! 应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n。
//! 
//! @example 
//! input:  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//! output: ans = [1,2,2,3,5,6]
//! 
//! @note 无
class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::copy_backward(nums1.begin(), nums1.begin() + m, nums1.end());
    auto it0 = nums1.begin();
    auto it1 = nums1.begin() + n;
    auto it2 = nums2.begin();

    while (it1 != nums1.end() && it2 != nums2.end()) {
      if (*it1 <= *it2) {
        *it0++ = *it1++;
      } else {
        *it0++ = *it2++;
      }
    }

    std::copy(it2, nums2.end(), it0);
    std::copy(it1, nums1.end(), it0);
  }
};


int main() {
  Solution sol;
  std::vector<int> nums1{1, 2, 3, 0, 0, 0};
  int m = 3;
  std::vector<int> nums2{2, 5, 6};
  int n = 3;
  sol.merge(nums1, m, nums2, n);

  for (auto &num : nums1) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}