
#include <vector>
#include <queue>
#include <iostream>

//! @brief 
//! 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//! 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//! 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
//! 
//! @details 
//! 1 <= k <= nums.length <= 105
//! -104 <= nums[i] <= 104
//! 
//! @example 
//! input:  [3,2,1,5,6,4], k = 2
//! output: 5
//! 
//! @note
//! 方法一：使用堆的时间复杂度是 O(nlogn)
//! 方法而：基于快速排序的选择方法，时间复杂度是 O(n)
//! 
class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (minHeap.size() < k) {
        minHeap.push(nums[i]);
      } else if (nums[i] > minHeap.top()) {
        minHeap.pop();
        minHeap.push(nums[i]);
      }
    }

    return minHeap.top();
  }

  int findKthLargest_2(std::vector<int>& nums, int k) {
    
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
