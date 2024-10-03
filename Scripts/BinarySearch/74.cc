
#include <vector>

//! @brief 
//! 给你一个满足以下两条属性的 m x n 整数矩阵：
//! 1. 每行中的整数从左到右按非严格递增顺序排列。
//! 2. 每行的第一个整数大于前一行的最后一个整数。
//! 
//! 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false。
//! 
//! @details 
//! 矩阵的大小为 m x n，其中：
//! - 1 <= m, n <= 100
//! - -10^4 <= matrix[i][j], target <= 10^4
//! 
//! @example 
//! input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//! output: true
//! 解释: target 3 在矩阵中。
//! 
//! input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//! output: false
//! 解释: target 13 不在矩阵中。
//! 
//! @note
//! 也可以通过坐标映射，仅仅一次二分查找即可完成
//! int low = 0, high = m * n - 1;
//! int mid = low + (high - low) / 2;
//! int value = matrix[mid / n][mid % n];
//! 
class Solution {
public:
  bool 
  searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
  {
    size_t row = lastLess(matrix, target);
    if (row == -1) return false;

    int low = 0, high = matrix[row].size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      auto value = matrix[row][mid];
      if (value > target) {
        high = mid - 1;
      } else if (value < target) {
        low = mid + 1;
      } else {
        return true;
      }
    }

    return false;
  }

private:
  size_t
  lastLess(std::vector<std::vector<int>>& matrix, int target)
  {
    int low = 0, high = matrix.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[mid][0] <= target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    if (high >= 0 && matrix[high][0] <= target) {
      return high;
    } else {
      return -1;
    }
  }
};

