
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
//! 方法二：基于快速排序的选择方法，时间复杂度是 O(n)
//! 
class Solution {
public:
  // int findKthLargest(std::vector<int>& nums, int k) {
  //   std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
  //   int n = nums.size();
  //   for (int i = 0; i < n; ++i) {
  //     if (minHeap.size() < k) {
  //       minHeap.push(nums[i]);
  //     } else if (nums[i] > minHeap.top()) {
  //       minHeap.pop();
  //       minHeap.push(nums[i]);
  //     }
  //   }

  //   return minHeap.top();
  // }

  int findKthLargest(std::vector<int>& nums, int k) {
    return findKthLargest(nums, k, 0, nums.size() - 1);
  }

private:
  int findKthLargest(std::vector<int>& nums, int k, int low, int high) {
    if (low == high)
      return low;

    int mid = this->partition(nums, low, high);
    
    if (k < mid + 1) {
      return findKthLargest(nums, k, low, mid - 1);
    } else if (k > mid + 1) {
      return findKthLargest(nums, k, mid + 1, high);
    } else {
      return nums[mid];
    }
  }

  int partition(std::vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; ++j) {
      if (nums[j] > pivot) {
        std::swap(nums[i], nums[j]);
        ++i;
      }
    }
    std::swap(nums[i], nums[high]);
    return i;
  }
};

//! @note Solution1 来自官方题解
//! 上面的常规 quick sort 写法的递归栈是线性增长。
//! 即在 100 个相等元素且 k = 50 时，栈堆叠了高达 50 个 frame
//! 而 Solution1 在这种情况下的递归栈是 logn 增长的，只有约 6 个 frame
//! 具体来说是 Lomuto 分区算法 与 Hoare 分区算法 的区别，
//! 后者专门由于优化大量元素相等时的递归栈深度退化问题。
//! 
class Solution1 {
public:
  int quickselect(std::vector<int> &nums, int l, int r, int k) {
    if (l == r)
      return nums[k];
    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j) {
      do i++; while (nums[i] < partition);
      do j--; while (nums[j] > partition);
      if (i < j)
        std::swap(nums[i], nums[j]);
    }
    if (k <= j)return quickselect(nums, l, j, k);
    else return quickselect(nums, j + 1, r, k);
  }

  int findKthLargest(std::vector<int> &nums, int k) {
    int n = nums.size();
    return quickselect(nums, 0, n - 1, n - k);
  }
};



int main() {
  Solution  sol;
  std::vector<int> vec{1,2,3,4,5};
  for (int i = 0; i < 95; ++i)
    vec.push_back(1);
  
  std::cout << sol.findKthLargest(vec, 50) << std::endl;
  return 0;
}

