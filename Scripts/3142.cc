#include <vector>
#include <iostream>

//! @brief 给你一个大小为mxn的二维矩阵grid。你需要判断每一个格子grid[i][j]是否满足：
//! 如果它下面的格子存在，那么它需要等于它下面的格子: grid[i][j] == grid[i+1][j]。
//! 如果它右边的格子存在，那么它需要不等于它右边的格子: grid[i][j] != grid[i][j+1]。
//! 如果 所有 格子都满足以上条件，那么返回 true ，否则返回 false 。
//!
//! @details
//! 1 <= n, m <= 10
//! 0 <= grid[i][j] <= 9
//! 
//! @example 
//! input:  grid = [[1,0,2],[1,0,2]]
//! output: true
//! input:  gas = grid = [[1,1,1],[0,0,0]]
//! output: false
//! 
class Solution {
public:
  bool satisfiesConditions(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    if (rows == 0) return false;
    int cols = grid[0].size();
    // check all columns
    for (int i = 0; i < cols; ++i) {
      for (int j = 1; j < rows; ++j) {
        if (grid[j][i] != grid[j - 1][i])
          return false;
      }
    }
    // check first row
    for (int i = 1; i < cols; ++i) {
      if (grid[0][i] == grid[0][i - 1])
        return false;
    }

    return true;
  }
};