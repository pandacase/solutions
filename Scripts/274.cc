#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 给你一个整数数组 citations ，其中 citations[i] 表示
//! 研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
//! 根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的
//! h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文
//! 被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数是其中最大的。
//!
//! @details
//! n == citations.length
//! 1 <= n <= 5000
//! 0 <= citations[i] <= 1000
//! 
//! @example
//! input:  citations = [3,0,6,1,5]
//! output: 3 
//! 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了:
//!  3, 0, 6, 1, 5 次。
//! 由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文
//! 每篇被引用 不多于 3 次，所以她的 h 指数是 3。
//! input:  citations = [1,3,1]
//! output: 1
//! 
class Solution {
public:
  //! @note 二分法，O(nlogn)，O(1)
  int hIndex(std::vector<int>& citations) {
    int size = citations.size();
    int left = 1, right = size;
    int ans = 0;
    while (left <= right) {
      int mid_h = left + (right - left) / 2;
      
      int cnt = 0;
      for (int i = 0; i < size; ++i) {
        if (citations[i] >= mid_h) ++cnt;
      }

      if (cnt < mid_h) {
        right = mid_h - 1;
      } else if (cnt > mid_h) {
        left = mid_h + 1;
        ans = mid_h;
      } else {
        ans = mid_h;
        break;
      }
    }
    return ans;
  };

  //! @note 排序，O(nlogn)，O(nlogn)
  // int hIndex(std::vector<int>& citations) {
  //   int size = citations.size();
  //   std::sort(citations.begin(), citations.end());
  //   int ans = 0, i = size - 1;
  //   for (; i >= 0 && citations[i] > ans; --i)
  //     ++ans;
  //   return ans;
  // }

  //! @note 计数数组，O(n)，O(n)
  //! ...
};


int main() {
  Solution sol;
  std::vector<int> nums{2,3,1,1,4};
  // 1 1 2 3 4
  // 0 1 2 3 4
  int ans = sol.hIndex(nums);

  std::cout << ans << std::endl;
}
