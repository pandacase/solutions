#include <unordered_map>
#include <vector>
#include <iostream>

//! @brief 
//! 给定一个mxn的矩阵，如果一个元素为0，则将其所在行和列的所有元素都设为0。
//! 请使用原地算法并尝试使用常数的额外空间而不仅限于 O(m+n)。
//! 
//! @details 
//! m == matrix.length
//! n == matrix[0].length
//! 1 <= m, n <= 200
//! -231 <= matrix[i][j] <= 231 - 1
//! 
//! @example 
//! input:  matrix = [[1,1,1],[1,0,1],[1,1,1]]
//! output: [[1,0,1],[0,0,0],[1,0,1]]
//! 
//! input:  matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//! output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//! 
//! @note
//! O(m+n)额外空间的做法是，使用两个集合标记出现过0的行和列，再遍历一遍置为0
//! 实际上可以使用第一行和第一列（除了0,0）来充当这个标记集合，
//! 然后使用额外 2 个 bool 来标记第一行/第一列是否出现了0.
//! 如果出现了，在最后把 第一行/第一列 全设为 0 即可，未出现则不用管
//! （因为如果某一位置被标记成了0，本来也会在第三步设0的时候被传染为0，
//!   没有被标记为0的，那这个数也不需要修改，所以只要 false 就不用管）
//!
//! 极致变态的方法：(Just for fun)
//! 注意到第三步置0的时候，0,0 是不需要用作标记的
//! 所以这一位置可以用来存储第一行是否出现了 0，然后就只需要额外的另一个 bool
//! 来标记第一列是否出现了 0 了。
//! 不过最后第四步的时候千万记得要先拿 matrix[0][0] 来判断第一行，
//! 防止被第一列置 0 的时候污染到了。
class Solution {
public:
    void 
    setZeroes(std::vector<std::vector<int>>& matrix) 
    {
      int m = matrix.size(), n = matrix[0].size();

      // Step 1: record if col-0 or row-0 has zero
      bool zeroFlagCol = false;
      for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
          zeroFlagCol = true;
          break;
        }
      }
      bool zeroFlagRow = false;
      for (int i = 0; i < n; ++i) {
        if (matrix[0][i] == 0) {
          zeroFlagRow = true;
          break;
        }
      }

      // Step 2: tag
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          if (matrix[i][j] == 0) {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }

      // Step 3: set zero
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
          }
        }
      }

      // Step 4: if needed, set zero for col-0 or row-0
      if (zeroFlagCol) {
        for (int i = 0; i < m; ++i) {
          matrix[i][0] = 0;
        }
      }
      if (zeroFlagRow) {
        for (int i = 0; i < n; ++i) {
          matrix[0][i] = 0;
        }
      }
    }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> matrix{
    {1,  2,  3,  4},
    {5,  0,  7,  8},
    {0,  10, 11, 12},
    {13, 14, 15, 0}
  };
  sol.setZeroes(matrix);

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
