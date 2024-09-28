#include <unordered_map>
#include <vector>
#include <iostream>

//! @brief 
//! 生命游戏，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
//! 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
//! 每个细胞都具有一个初始状态： 1 即为活细胞（live），或0即为死细胞（dead）。
//! 
//! 每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//! 1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//! 2. 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//! 3. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//! 4. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//! 
//! 下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，
//! 其中细胞的出生和死亡是同时发生的。
//! 给你 m x n 网格面板 board 的当前状态，返回下一个状态。
//! 
//! @details 
//! m == board.length
//! n == board[i].length
//! 1 <= m, n <= 25
//! board[i][j] 为 0 或 1
//! 
//! @example 
//! input:  board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
//! output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
//! 
//! input:  board = [[1,1],[1,0]]
//! output: [[1,1],[1,1]]
//! 
//! @note
//! 进阶：你可以使用原地算法解决本题吗？
//!
//! 本题使用二维数组来表示面板。原则上，面板是无限的，
//! 但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
//! 
class Solution {
public:
  void 
  gameOfLife(std::vector<std::vector<int>>& board) 
  {
    int m = board.size(), n = board[0].size();

    // check and tag current frame
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        size_t live_cnt = this->countLive(board, i, j);
        int& curr = board[i][j];
        
        if (curr == static_cast<int>(CellState::alive)) {
          if (live_cnt < 2 || live_cnt > 3) {
            curr = static_cast<int>(CellState::alive2dead);
          }
        } else {
          if (live_cnt == 3) {
            curr = static_cast<int>(CellState::dead2alive);
          }
        }
      }
    }

    // update to next frame
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int& curr = board[i][j];
        if (curr == static_cast<int>(CellState::alive2dead)) {
          curr = static_cast<int>(CellState::dead);
        } 
        else if (curr == static_cast<int>(CellState::dead2alive)) {
          curr = static_cast<int>(CellState::alive);
        }
      }
    }
  }

private:
  std::vector<std::vector<int>> directions{
    {1, 1}, {1, 0}, {1, -1}, {0, -1},
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}
  };

  enum class CellState {
    dead2alive = -1,
    dead = 0,
    alive = 1,
    alive2dead = 2
  };

  size_t
  countLive(std::vector<std::vector<int>>& board, size_t i, size_t j) {
    size_t live_cnt = 0;
    for (auto& dir : directions) {
      int new_i = i + dir[0], new_j = j + dir[1];
      if (this->isValid(board, new_i, new_j)) {
        int curr = board[new_i][new_j];
        if (curr == static_cast<int>(CellState::alive) || 
            curr == static_cast<int>(CellState::alive2dead)) {
          live_cnt += 1;
        }
      }
    }
    return live_cnt;
  }

  bool
  isValid(std::vector<std::vector<int>>& board, size_t i, size_t j) {
    if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
      return true;
    else
      return false;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> board{
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 0}
  };
  sol.gameOfLife(board);

  //! 2
  for (auto & vec : board) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}
