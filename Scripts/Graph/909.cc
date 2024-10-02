
#include <iostream>
#include <vector>
#include <queue>

//! @brief 
//! 给定一个大小为 n x n 的整数矩阵 board，方格按从 1 到 n^2 编号，
//! 编号遵循转行交替方式，从左下角开始（即，从 board[n - 1][0] 开始）
//! 的每一行改变方向。
//! 玩家从棋盘上的方格 1 开始，每回合从当前方格 curr 出发前进：
//! - 选定目标方格 next，目标方格的编号在范围 [curr + 1, min(curr + 6, n^2)]。
//! - 若 next 存在蛇或梯子，则传送到 board[r][c] 指定的目的地，
//!   否则玩家传送到目标方格 next。
//! - 当玩家到达编号为 n^2 的方格时，游戏结束。
//! 玩家在每回合最多只能经过一个蛇或梯子，不允许连续传送。
//! 返回达到编号为 n^2 的方格所需的最少移动次数，若无法到达则返回 -1。
//! 
//! @details 
//! n == board.length == board[i].length
//! 2 <= n <= 20
//! board[i][j] 的值是 -1 或在范围 [1, n^2] 内。
//! 编号为 1 和 n^2 的方格上没有蛇或梯子。
//! 
//! @example 
//! input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],
//!                 [-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],
//!                 [-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
//! output: 4
//! 解释: 玩家从方格 1 出发，经过以下步骤到达方格 36：
//! - 移动到方格 2，爬梯子到方格 15。
//! - 移动到方格 17，爬蛇到方格 13。
//! - 移动到方格 14，爬梯子到方格 35。
//! - 移动到方格 36，游戏结束。
//! 
//! input: board = [[-1,-1],[-1,3]]
//! output: 1
//! 解释: 玩家从方格 1 移动到方格 2，并爬梯子到方格 3。
//! 
//! @note 
//! 
class Solution {
public:
  using Position = std::pair<size_t, size_t>;
private:
  using IdxSteps = std::pair<size_t, size_t>;

public:
  int 
  snakesAndLadders(std::vector<std::vector<int>>& board) 
  {
    size_t n{board.size()}, idx_num{n * n};
    
    std::vector<bool> visited(idx_num + 1);
    std::queue<IdxSteps> queue;
    visited[1] = true;
    queue.emplace(1, 0);

    while (!queue.empty()) {
      auto curr = queue.front();
      queue.pop();
      
      auto nexts = next(board, visited, curr.first);
      for (auto& next : nexts) {
        if (next == idx_num)
          return curr.second + 1;
        else
          queue.emplace(next, curr.second + 1);
      }
    }

    return -1;
  }

private:
  std::vector<size_t>
  next(
    std::vector<std::vector<int>>& board, 
    std::vector<bool>& visited, 
    size_t curr)
  {
    const size_t RANGE = 6;
    size_t n{board.size()}, idx_num{n * n};

    std::vector<size_t> nexts;
    for (size_t i = 1; i <= RANGE; ++i) {
      auto next = curr + i;

      if (next > idx_num) break;
      else if (!visited[next]) {
        visited[next] = true;
        auto pos = idx2Pos(n, next);
        auto tele = board[pos.first][pos.second];
        nexts.push_back(tele == -1 ? (next) : tele);
      }
    }

    return nexts;
  }

  Position
  idx2Pos(const size_t n, const size_t idx) 
  {
    size_t row = (idx - 1) / n;
    size_t col = (idx - 1) % n;
    if (row % 2 == 0) {
      // from left to right
      return {n - 1 - row, col};
    } else {
      // from right to left
      return {n - 1 - row, n - 1 - col};
    }
  }
};


int
main()
{
  std::vector<std::vector<int>> board{
    {1,1,-1},{1,1,1},{-1,1,1}
  };

  Solution sol;
  auto ans = sol.snakesAndLadders(board);
  std::cout << ans << std::endl;
}