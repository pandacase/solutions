
#include <vector>
#include <iostream>
#include <unordered_set>
#include <array>

//! @brief 
//! 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
//! 返回执行此操作后，grid 中最大的岛屿面积是多少？
//! 岛屿 由一组上、下、左、右四个方向相连的 1 形成。
//! 
//! @details 
//! m == grid.length
//! n == grid[i].length
//! 1 <= m, n <= 500
//! grid[i][j] 的值为 '0' 或 '1'
//! 
//! @example 
//! input:  grid = [[1, 0], [0, 1]]
//! output: 3
//! 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
//! 
//! @note
//! 目前这个版本是 TLE，测例通过 72/75，等待解决中...
//!
//! 优化：
//! 1. 在生成新的方向时 reserve(4)
//! 2. 返回新的方向 vec 时使用 sdt::move()
//! 3. countNewArea 中 areas 改为传引用（这个至关重要，前面疏忽了）
//! 4. 将四个方向的数组改成 array
//! 5. 多次对 grid[new_i][new_j] 的访问改为先存到本地 idx 变量之后访问 idx
//!    (这本质上是 cache locality 的优化)
//! 
//! 不过时间消耗还是偏多了，等待重构中....
//!
class Solution {
public:
  int 
  largestIsland(std::vector<std::vector<int>>& grid) 
  {
    size_t m = grid.size(), n = grid[0].size();
    size_t index = 2; //! index of area starts at 2
    std::vector<size_t> areas{std::initializer_list<size_t>{0, 0}};
    std::vector<std::pair<int, int>> tagged_straits;

    size_t max_area = 0;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          areas.push_back(countArea(grid, i, j, index));
          max_area = std::max(max_area, areas.back());
          index += 1;
        } else if (grid[i][j] == 0) {
          if (checkStrait(grid, i, j) >= 2) {
            tagged_straits.emplace_back(i, j);
          }
        }
      }
    }

    size_t ans = 0, new_area = 0;
    for (auto& [i, j] : tagged_straits) {
      new_area = countNewArea(grid, i, j, areas);
      ans = std::max(ans, new_area);
    }

    if (tagged_straits.empty()) {
      //! check if no more than one islands can be connected by
      //! one grid of land.
      ans = std::min(m * n, max_area + 1);
    } else if (areas.size() == 2) {
      // check if all water
      ans = 1;
    }

    return ans;
  }

private:
  bool
  isValid(std::vector<std::vector<int>>& grid, size_t i, size_t j) 
  {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
  }
  
  std::vector<std::pair<int, int>>
  generateDirs(std::vector<std::vector<int>>& grid, size_t i, size_t j) 
  {
    std::vector<std::pair<int, int>> new_dirs;
    new_dirs.reserve(_dirs_num);
    for (auto& dir : _dirs) {
      size_t new_i = i + dir[0], new_j = j + dir[1];
      if (this->isValid(grid, new_i, new_j)) {
        new_dirs.emplace_back(new_i, new_j);
      }
    }
    return std::move(new_dirs);
  }

private:
  size_t
  countArea(
    std::vector<std::vector<int>>& grid, 
    size_t i, size_t j, size_t& index
  ) {
    if (grid[i][j] != 1) {
      return 0;
    }

    // tag visitied
    grid[i][j] = index;

    size_t ans = 1;
    auto new_dirs = generateDirs(grid, i, j);
    for (auto& [new_i, new_j] : new_dirs) {
      ans += countArea(grid, new_i, new_j, index);
    }
    return ans;
  }

  size_t 
  checkStrait(
    std::vector<std::vector<int>>& grid, size_t i, size_t j)
  {
    size_t lands = 0;
    auto new_dirs = generateDirs(grid, i, j);
    for (auto& [new_i, new_j] : new_dirs) {
      lands += grid[new_i][new_j];
    }
    return lands;
  }

  size_t
  countNewArea(
    std::vector<std::vector<int>>& grid,
    size_t i, size_t j,
    std::vector<size_t>& areas
  ) {
    size_t new_area = 1;
    std::unordered_set<size_t> counted;
    auto new_dirs = generateDirs(grid, i, j);
    for (auto& [new_i, new_j] : new_dirs) {
      int idx = grid[new_i][new_j];
      if (!counted.count(idx)) {
        new_area += areas[idx];
        counted.insert(idx);
      }
    }
    return new_area;
  }

private:
  const size_t _dirs_num = 4;
  std::array<std::array<int, 2>, 4> _dirs{{
    {1, 0},   // to down
    {-1, 0},  // to up
    {0, 1},   // to right
    {0, -1}   // to left
  }};
};


int main() {
  Solution sol;
  std::vector<std::vector<int>> grid = {
    {1, 0},
    {0, 1}
  };
  auto ans = sol.largestIsland(grid);

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
