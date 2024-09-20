
#include <vector>
#include <unordered_set>
#include <iostream>

//! @brief 
//! 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
//! 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
//! 区域：连接所有 'O' 的单元格来形成一个区域。
//! 围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 
//! board 边缘，则该区域被 'X' 单元格围绕。
//! 通过将输入矩阵 board 中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。
//! 
//! @details 
//! m == board.length
//! n == board[i].length
//! 1 <= m, n <= 200
//! board[i][j] 为 'X' 或 'O'
//! 
//! @example 
//! input:  board = [
//!                   ["X","X","X","X"],
//!                   ["X","O","O","X"],
//!                   ["X","X","O","X"],
//!                   ["X","O","X","X"]
//!                 ]
//! output:         [
//!                   ["X","X","X","X"],
//!                   ["X","X","X","X"],
//!                   ["X","X","X","X"],
//!                   ["X","O","X","X"]
//!                 ]
//! 
//! @note
//! 
//!
class Solution {
public:
  void 
  solve(std::vector<std::vector<char>>& board) 
  {
    int m = board.size(), n = board[0].size();
    std::vector<std::pair<int, int>> tagged_pos;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O') {
          if (!checkIslands(board, i ,j)) {
            this->cover(board, i, j, 'X');
          } else {
            tagged_pos.emplace_back(i, j);
          }
        }
      }
    }

    for (auto& [i, j] : tagged_pos) {
      this->cover(board, i, j, 'O');
    }
  }

private:
  bool
  isValid(std::vector<std::vector<char>>& board, size_t i, size_t j) 
  {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
  }

  bool
  checkIslands(std::vector<std::vector<char>>& board, size_t i, size_t j) 
  {
    if (!isValid(board, i, j)) {
      return true;
    } else if (board[i][j] != 'O') {
      return false;
    }

    // tag visited
    board[i][j] = 'A';

    bool ans = false;
    ans = checkIslands(board, i + 1, j) | ans;
    ans = checkIslands(board, i - 1, j) | ans;
    ans = checkIslands(board, i, j + 1) | ans;
    ans = checkIslands(board, i, j - 1) | ans;
    return ans;
  }

  void
  cover(std::vector<std::vector<char>>& board,
               size_t i, size_t j, char ch) 
  {
    if (!isValid(board, i, j)) {
      return;
    } else if (board[i][j] != 'A') {
      return;
    }

    board[i][j] = ch;

    cover(board, i + 1, j, ch);
    cover(board, i - 1, j, ch);
    cover(board, i, j + 1, ch);
    cover(board, i, j - 1, ch);
  }
};

int main() {
  Solution sol;
  // std::vector<std::vector<char>> board{
  //   {'O','O','O','O','X','X'},
  //   {'O','O','O','O','O','O'},
  //   {'O','X','O','X','O','O'},
  //   {'O','X','O','O','X','O'},
  //   {'O','X','O','X','O','O'},
  //   {'O','X','O','O','O','O'}
  // };
  std::vector<std::vector<char>> board{
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'}
  };
  sol.solve(board);

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  for (auto & vec : board) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}
