#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 
//! 以数组 intervals 表示若干个区间的集合，其中单个区间为
//!  intervals[i] = [starti, endi]。请你合并所有重叠的区间，
//! 并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
//! 
//! @details 
//! 1 <= intervals.length <= 104
//! intervals[i].length == 2
//! 0 <= starti <= endi <= 104
//! 
//! @example 
//! input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
//! output: [[1,6],[8,10],[15,18]]
//! 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//! 
//! input:  intervals = [[1,4],[4,5]]
//! output: [[1,5]]
//! 区间 [1,4] 和 [4,5] 可被视为重叠区间。
//! 
//! @note
//! 
class Solution {
public:
  std::vector<std::vector<int>> 
  merge(std::vector<std::vector<int>>& intervals) 
  {
    size_t n = intervals.size();
    std::sort(intervals.begin(), intervals.end(), 
              [](const std::vector<int>& a, std::vector<int>& b) {
                return a[0] < b[0];
              });

    std::vector<std::vector<int>>  ans;
    int begin, end;
    for (int i = 0; i < n; ++i) {
      if (i >= 1 && intervals[i][0] <= ans.back()[1]) {
        ans.back()[1] = std::max(ans.back()[1], intervals[i][1]);
      } else {
        ans.push_back({intervals[i][0], intervals[i][1]});
      }
    }
    return ans;
  }
};


int main() {
  Solution sol;
  std::vector<std::vector<int>> asd{
    {1, 3}, {2, 6}, {8, 10}, {15, 18}, {20, 21}
  };
  auto ans = sol.merge(asd);

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  for (auto & vec : ans) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}
