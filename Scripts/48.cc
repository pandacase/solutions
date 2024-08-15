#include <unordered_map>
#include <vector>
#include <iostream>

//! @brief 
//! 给定一个n×n的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转90度。
//! 你必须在 原地 旋转图像。
//! 
//! @details 
//! n == matrix.length == matrix[i].length
//! 1 <= n <= 20
//! -1000 <= matrix[i][j] <= 1000
//! 
//! @example 
//! input:  matrix = [[1,2,3],[4,5,6],[7,8,9]]
//! output: [[7,4,1],[8,5,2],[9,6,3]]
//! 
//! input:  matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//! output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
//! 
//! @note
//! n = 4
//! lIdx = 0
//! 0,0 -> 0,3 -> 3,3 -> 3,0
//! 0,1 -> 1,3 -> 3,2 -> 2,0
//! 0,2 -> 2,3 -> 3,1 -> 1,0
//! ------------------------
//! lIdx = 1
//! 1,1 -> 1,2 -> 2,2 -> 2,1
class Solution {
public:
  void 
  rotate(std::vector<std::vector<int>>& matrix) 
  {
    int n = matrix.size(), layer = n / 2;
    for (int lIdx = 0; lIdx < layer; ++lIdx) {
      for (int i = lIdx; i < n - 1 - lIdx; ++i) {
        // get 4 corner.
        int& topLeft     = matrix[lIdx][i];
        int& topRight    = matrix[i][(n - 1) - lIdx];
        int& bottomRight = matrix[(n - 1) - lIdx][(n - 1) - i];
        int& bottomLeft  = matrix[(n - 1) - i][lIdx];
        
        // rotate 4 corner.
        int tmp     = bottomLeft;
        bottomLeft  = bottomRight;
        bottomRight = topRight;
        topRight    = topLeft;
        topLeft     = tmp;
      }
    }
  }
};


int main() {
  Solution sol;
  std::vector<std::vector<int>> matrix{
    {5,1,9,11},
    {2,4,8,10},
    {13,3,6,7},
    {15,14,12,16}
  };
  sol.rotate(matrix);

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  for (auto & vec : matrix) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}
