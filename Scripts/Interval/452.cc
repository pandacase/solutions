#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <optional>


//! @brief 
//! 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录
//! 在整数数组 points 中，其中 points[i] = [xstart, xend] 表示水平
//! 直径在 xstart 和 xend 之间的气球。你不知道气球的确切 y 坐标。
//! 
//! 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出
//! 一支箭，若有一个气球的直径的开始和结束坐标为 xstart, xend，且
//! 满足 xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数
//! 量没有限制。弓箭一旦被射出之后，可以无限地前进。
//! 
//! 给你一个数组 points，返回引爆所有气球所必须射出的最小弓箭数。
//! 
//! @details 
//! 1 <= points.length <= 105
//! points[i].length == 2
//! -2^31 <= xstart < xend <= 2^31 - 1
//! 
//! @example 
//! input: points = [[10,16],[2,8],[1,6],[7,12]]
//! output: 2
//! 解释: 气球可以用 2 支箭来爆破：
//! - 在 x = 6 处射出箭，击破气球 [2,8] 和 [1,6]。
//! - 在 x = 11 处发射箭，击破气球 [10,16] 和 [7,12]。
//! 
//! input: points = [[1,2],[3,4],[5,6],[7,8]]
//! output: 4
//! 解释: 每个气球需要射出一支箭，总共需要 4 支箭。
//! 
//! input: points = [[1,2],[2,3],[3,4],[4,5]]
//! output: 2
//! 解释: 气球可以用 2 支箭来爆破：
//! - 在 x = 2 处发射箭，击破气球 [1,2] 和 [2,3]。
//! - 在 x = 4 处射出箭，击破气球 [3,4] 和 [4,5]。
//! 
//! @note
//! 
class Solution {
public:
  int 
  findMinArrowShots(std::vector<std::vector<int>>& points) 
  {
    int n = points.size();
    
    std::sort(
      points.begin(), points.end(), 
      [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
      }
    );

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      auto curr_inter = points[i];
      while (i + 1 < n) {
        auto p = intersect(curr_inter, points[i + 1]);
        if (p == std::nullopt)
          break;
        curr_inter = *p;
        ++i;
      }
      ans += 1;
    }

    return ans;
  }

  int 
  findMinArrowShots_2(std::vector<std::vector<int>>& points) 
  {
    int n = points.size();
    
    std::sort(
      points.begin(), points.end(), 
      [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
      }
    );

    int ans = 1;
    int prev = points[0][1];
    for (int i = 1; i < n; ++i) {
      if (points[i][0] > prev) {
        prev = points[i][1];
        ans += 1;
      }
    }

    return ans;
  }

private:
  std::optional<std::vector<int>>
  intersect(std::vector<int>& inter_a, std::vector<int>& inter_b)
  {
    int inter_l = std::max(inter_a[0], inter_b[0]);
    int inter_r = std::min(inter_a[1], inter_b[1]);
    if (inter_l <= inter_r) {
      return std::optional<std::vector<int>>({inter_l, inter_r});
    } else {
      return std::nullopt;
    }
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> asd{
    {3, 9},
    {7, 12},
    {3, 8},
    {6, 8},
    {9, 10},
    {2, 9},
    {0, 9},
    {3, 9},
    {0, 6},
    {2, 8}
  };
  auto ans = sol.findMinArrowShots_2(asd);

  //! 0
  std::cout << ans << std::endl;
}
