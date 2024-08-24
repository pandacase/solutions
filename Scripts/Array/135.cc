#include <vector>
#include <iostream>
#include <numeric>

//! @brief n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
// 你需要按照以下要求，给这些孩子分发糖果：
// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
//!
//! @details
//! n == ratings.length
//! 1 <= n <= 2 * 10^4
//! 0 <= ratings[i] <= 2 * 10*4
//! 
//! @example 
//! input:  ratings = [1,0,2]
//! output: 5 
//! 糖果分发：[2,1,2]
//! input:  ratings = [1,2,2]
//! output: 4
//! 糖果分发：[1,2,1]
//!  
//! @note
//! 先找出所有局部最低点的下标值，然后分别在那些下标值开始前后遍历。
//! 优化：可以直接从前往后、从后往前分别一次遍历，不需要先找局部最低点。
class Solution {
public:
  int candy(std::vector<int>& ratings) {
    int size = ratings.size();

    // find out all local minimum
    std::vector<int> localMinPoints;
    for (int i = 0; i < size; ++i) {
      if (i == 0) {
        if (i + 1 == size 
            || ratings[i] <= ratings[i + 1] ) {
          localMinPoints.push_back(i); 
        }
      } else if (i == size - 1) {
        if (i - 1 < 0
            || ratings[i] <= ratings[i - 1]) {
          localMinPoints.push_back(i);
        }
      } else {
        if (ratings[i] <= ratings[i - 1] 
            && ratings[i] <= ratings[i + 1]) {
          localMinPoints.push_back(i);
        }
      }
    }

    std::vector<int> candies(size, 1);
    for (auto &point : localMinPoints) {
      for (int i = point - 1; i >=0; --i) {
        if (ratings[i] > ratings[i + 1]) {
          candies[i] = std::max(candies[i], candies[i + 1] + 1);
        } else break;
      }

      for (int i = point + 1; i < size; ++i) {
        if (ratings[i] > ratings[i - 1]) {
          candies[i] = std::max(candies[i], candies[i - 1] + 1);
        } else break;
      }
    }

    return std::accumulate(candies.begin(), candies.end(), 0);
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{1,3,5,3,2,1};
  int ans = sol.candy(nums);

  std::cout << ans << std::endl;
}
