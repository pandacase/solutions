#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//! @brief 
//! 给你一个无重叠的，按照区间起始端点排序的区间列表 intervals，
//! 其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，
//! 并且 intervals 按照 starti 升序排列。
//! 同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
//! 
//! 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 
//! 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
//!
//! 返回插入之后的 intervals。
//!
//! 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。
//! 
//! @details 
//! 0 <= intervals.length <= 104
//! intervals[i].length == 2
//! 0 <= starti <= endi <= 105
//! intervals 根据 starti 按 升序 排列
//! newInterval.length == 2
//! 0 <= start <= end <= 105
//! 
//! @example 
//! input:  intervals = [[1,3],[6,9]], newInterval = [2,5]
//! output: [[1,5],[6,9]]
//! 
//! input:  intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], 
//!         newInterval = [4,8]
//! output: [[1,2],[3,10],[12,16]]
//! 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
//! 
//! @note
//! 
class Solution {
public:
  std::vector<std::vector<int>> 
  insert(
    std::vector<std::vector<int>>& intervals, 
    std::vector<int>& newInterval
  ) {
    std::vector<std::vector<int>> ans;

    bool inserted = false;
    
    for (auto& inter : intervals) {
      if (inter[1] < newInterval[0]) {
        ans.push_back(inter);
      } else if (inter[0] > newInterval[1]) {
        this->tryInsert(ans, inserted, newInterval);
        ans.push_back(inter);
      } else {
        newInterval[0] = std::min(newInterval[0], inter[0]);
        newInterval[1] = std::max(newInterval[1], inter[1]);
      }
    }
    this->tryInsert(ans, inserted, newInterval);

    return ans;
  }

private:
  void
  tryInsert(
    std::vector<std::vector<int>>& ans, 
    bool& inserted, std::vector<int>& newInterval
  ) {
    if (!inserted) {
        ans.push_back(newInterval);
        inserted = true;
    }
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> asd{ {1, 3}, {6, 9} };
  std::vector<int> tp{ 2, 5 };
  auto ans = sol.insert(asd, tp);

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
