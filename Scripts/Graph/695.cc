
#include <vector>
#include <queue>
#include <iostream>

//! @brief 
//! 给你一个大小为 m x n 的二进制矩阵 grid 。
//! 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在
//! 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
//! 岛屿的面积是岛上值为 1 的单元格的数目。
//! 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
//! 
//! @details 
//! m == grid.length
//! n == grid[i].length
//! 1 <= m, n <= 300
//! grid[i][j] 的值为 '0' 或 '1'
//! 
//! @example 
//! input:  grid = [
//!                  ["1","1","1","1","0"],
//!                  ["1","1","0","1","0"],
//!                  ["1","1","0","0","0"],
//!                  ["0","0","0","0","0"]
//!                ]
//! output: 1
//! 
//! @note
//! 
//!
class Solution {
public:
  int 
  maxAreaOfIsland(std::vector<std::vector<int>>& grid) 
  {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int area = countArea(grid, i, j);
          ans = std::max(area, ans);
        }
      }
    }
    return ans;
  }

private:
  int
  countArea(std::vector<std::vector<int>>& grid, int i, int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return 0;
    } else if (grid[i][j] != 1) {
      return 0;
    }

    // tag visitied
    grid[i][j] = 2;

    return 1
      + countArea(grid, i + 1, j)
      + countArea(grid, i - 1, j)
      + countArea(grid, i, j + 1)
      + countArea(grid, i, j - 1);
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
