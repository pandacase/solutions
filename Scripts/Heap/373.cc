
#include <vector>
#include <queue>
#include <iostream>

//! @brief 
//! 给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
//! 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
//! 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
//! 
//! @details 
//! 1 <= nums1.length, nums2.length <= 105
//! -109 <= nums1[i], nums2[i] <= 109
//! nums1 和 nums2 均为 升序排列
//! 1 <= k <= 104
//! k <= nums1.length * nums2.length
//! 
//! @example 
//! input:  nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//! output: [1,2],[1,4],[1,6]
//! 返回序列中的前 3 对数：
//! [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//! 
//! @note
//! 从 index[0, 0] 开始是最小的，往后有 2 个途径 [1, 0] 和 [0, 1]，
//! 将树展开会发现左子树的右子结点和右子树的左子结点会重合，
//! 所以可以每次只往右结点展开，然后在一开始把完全向左的遍历先提前填入队列中
//!
class Solution {
public:
  std::vector<std::vector<int>> 
  kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) 
  {
    int size1 = nums1.size(), size2 = nums2.size();
    std::vector<std::vector<int>> ans;

    auto cmp = [&nums1, &nums2](
      const std::pair<int, int>& a, 
      const std::pair<int, int>& b
    ) { 
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; 
    };
    std::priority_queue<
      std::pair<int, int>, 
      std::vector<std::pair<int, int>>, 
      decltype(cmp)
    > minHeap(cmp);

    for (int i = 0; i < std::min(size1, k); ++i) {
      minHeap.emplace(i, 0);
    }

    while (k--) {
      auto [x, y] = minHeap.top();
      minHeap.pop();
      ans.emplace_back(std::initializer_list<int>{nums1[x], nums2[y]});
      if (y + 1 < size2)
        minHeap.emplace(x, y + 1);
    }
  
    return ans;
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
