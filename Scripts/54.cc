#include <unordered_map>
#include <vector>
#include <iostream>

//! @brief 
//! 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，
//! 返回矩阵中的所有元素。
//! 
//! @details 
//! m == matrix.length
//! n == matrix[i].length
//! 1 <= m, n <= 10
//! -100 <= matrix[i][j] <= 100
//! 
//! @example 
//! input:  matrix = [[1,2,3],[4,5,6],[7,8,9]]
//! output: [1,2,3,6,9,8,7,4,5]
//! 
//! input:  matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//! output: [1,2,3,4,8,12,11,10,9,5,6,7]
//! 
//! @note
//! 
class Solution {
public:
  std::vector<int> 
  spiralOrder(std::vector<std::vector<int>>& matrix) 
  {
    int size = matrix.size() * matrix[0].size();
    
    // 4 directions
    std::vector<std::vector<int>> directions{
      {0, 1},
      {1, 0},
      {0, -1},
      {-1, 0}
    };

    // 4 bounds
    std::unordered_map<char, std::vector<int>> bounds{
      {'x', {0, (int)matrix[0].size() - 1}},
      {'y', {1, (int)matrix.size() - 1}}
    };

    int xIdx = 0, yIdx = 0, dIdx = 0;
    std::vector<int> ans(size, 0);
    for (int i = 0; i < size; ++i) {
      ans[i] = matrix[xIdx][yIdx];
      checkDirection(bounds, xIdx, yIdx, dIdx);
      xIdx += directions[dIdx][0];
      yIdx += directions[dIdx][1];
    }

    return ans;
  }

  void
  checkDirection(
    std::unordered_map<char, std::vector<int>>& bounds,
    int& xIdx, int& yIdx, int& dIdx) 
  {
    if (dIdx == 0 && yIdx == bounds['x'][1]) {
      dIdx = 1;
      bounds['x'][1] -= 1;
    } else if (dIdx == 1 && xIdx == bounds['y'][1]) {
      dIdx = 2;
      bounds['y'][1] -= 1;
    } else if (dIdx == 2 && yIdx == bounds['x'][0]) {
      dIdx = 3;
      bounds['x'][0] += 1;
    } else if (dIdx == 3 && xIdx == bounds['y'][0]) {
      dIdx = 0;
      bounds['y'][0] += 1;
    }
  }
};


int main() {
  Solution sol;
  std::vector<std::vector<int>> matrix{
    {1, 2, 3, 1},
    {4, 5, 6, 2},
    {7, 8, 9, 3}
  };
  auto ans = sol.spiralOrder(matrix);

  //! 0  
  // std::cout << ans << std::endl;

  //! 1
  for (auto & a : ans)
    std::cout << a << " ";
  std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
