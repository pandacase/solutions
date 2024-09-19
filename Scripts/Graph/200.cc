
#include <vector>
#include <queue>
#include <iostream>

//! @brief 
//! 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//! 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//! 此外，你可以假设该网格的四条边均被水包围。
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
  numIslands(std::vector<std::vector<char>>& grid) 
  {
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ans += 1;
        }
      }
    }
    return ans;
  }

private:
  void
  dfs(std::vector<std::vector<char>>& grid, int i, int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return;
    } else if (grid[i][j] != '1') {
      return;
    }

    // tag visitied
    grid[i][j] = '2';

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
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
