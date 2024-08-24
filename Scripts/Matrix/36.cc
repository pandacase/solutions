#include <unordered_set>
#include <vector>
#include <iostream>

#define SIZE 9
#define BLOCK_SIZE 3

//! @brief 
//! 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，
//! 验证已经填入的数字是否有效即可。
//! 数字 1-9 在每一行只能出现一次。
//! 数字 1-9 在每一列只能出现一次。
//! 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//! https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/12/250px-sudoku-by-l2g-20050714svg.png
//! 
//! @details 
//! 一个有效的数独（部分已被填充）不一定是可解的。
//! 只需要根据以上规则，验证已经填入的数字是否有效即可。
//! 空白格用 '.' 表示。
//! 
//! @example 
//! input:  board = 
//!         [["5","3",".",".","7",".",".",".","."]
//!         ,["6",".",".","1","9","5",".",".","."]
//!         ,[".","9","8",".",".",".",".","6","."]
//!         ,["8",".",".",".","6",".",".",".","3"]
//!         ,["4",".",".","8",".","3",".",".","1"]
//!         ,["7",".",".",".","2",".",".",".","6"]
//!         ,[".","6",".",".",".",".","2","8","."]
//!         ,[".",".",".","4","1","9",".",".","5"]
//!         ,[".",".",".",".","8",".",".","7","9"]]
//! output: true
//! 
//! input:  board = 
//!         [["8","3",".",".","7",".",".",".","."]
//!         ,["6",".",".","1","9","5",".",".","."]
//!         ,[".","9","8",".",".",".",".","6","."]
//!         ,["8",".",".",".","6",".",".",".","3"]
//!         ,["4",".",".","8",".","3",".",".","1"]
//!         ,["7",".",".",".","2",".",".",".","6"]
//!         ,[".","6",".",".",".",".","2","8","."]
//!         ,[".",".",".","4","1","9",".",".","5"]
//!         ,[".",".",".",".","8",".",".","7","9"]]
//! output: false
//! 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 
//! 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 
//! 因此这个数独是无效的。
//! 
//! @note
//! （其实可以使用三个哈希，然后遍历一遍即可）
class Solution {
public:
  bool 
  isValidSudoku(std::vector<std::vector<char>>& board) 
  {
    // check row
    for (int i = 0; i < SIZE; ++i) {
      std::unordered_set<char> nums;
      nums.reserve(SIZE);
      for (int j = 0; j < SIZE; ++j) {
        if (board[i][j] == '.')
          continue;
        else if (!nums.count(board[i][j]))
          nums.insert(board[i][j]);
        else
          return false;
      }
    }

    // check col
    for (int i = 0; i < SIZE; ++i) {
      std::unordered_set<char> nums;
      nums.reserve(SIZE);
      for (int j = 0; j < SIZE; ++j) {
        if (board[j][i] == '.')
          continue;
        else if (!nums.count(board[j][i]))
          nums.insert(board[j][i]);
        else
          return false;
      }
    }

    // check block
    for (int i = 0; i < BLOCK_SIZE; ++i) {
      for (int j = 0; j < BLOCK_SIZE; ++j) {
        std::unordered_set<char> nums;
        nums.reserve(SIZE);
        for (int ii = 0; ii < BLOCK_SIZE; ++ii) {
          for (int jj = 0; jj < BLOCK_SIZE; ++jj) {
            int rowIdx = i * BLOCK_SIZE + ii;
            int colIdx = j * BLOCK_SIZE + jj;
            if (board[rowIdx][colIdx] == '.')
              continue;
            else if (!nums.count(board[rowIdx][colIdx]))
              nums.insert(board[rowIdx][colIdx]);
            else
              return false;
          }
        }
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<char>> matrix{
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  auto ans = sol.isValidSudoku(matrix);

  //! 0  
  std::cout << ans << std::endl;

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
