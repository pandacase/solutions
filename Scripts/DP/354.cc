
#include <vector>
#include <iostream>
#include <unordered_map>

//! @brief 
//! 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，
//! 表示第 i 个信封的宽度和高度。
//! 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进
//! 另一个信封里，如同俄罗斯套娃一样。
//! 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封
//! （即可以把一个信封放到另一个信封里面）。
//! 注意：不允许旋转信封。
//! 
//! @details 
//! 1 <= envelopes.length <= 105
//! envelopes[i].length == 2
//! 1 <= wi, hi <= 105
//! 
//! @example
//! inputs: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//! output: 3
//! 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
//! 
//! inputs: envelopes = [[1,1],[1,1],[1,1]]
//! output: 1
//! 
//! @note
//! 按照 width 升序，可以把二维降低成一维问题，
//! 若 width 相等，则按照 height 倒序。这样可以保障不会在相等 width
//! 的情况下 push_back 很多个高度递增的 height 信封上去
//! 
class Solution {
public:
  static int 
  maxEnvelopes(std::vector<std::vector<int>>& envelopes) 
  {
    int n = envelopes.size();

    sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    std::vector<int> min_h_terminal{envelopes[0][1]};
    for (int i = 1; i < n; ++i) {
      if (int num = envelopes[i][1]; num > min_h_terminal.back()) {
        min_h_terminal.push_back(num);
      } else {
        size_t j = first_greater_equal(min_h_terminal, num);
        min_h_terminal[j] = num;
      }
    }

    return min_h_terminal.size();
  }

private:
  static size_t
  first_greater_equal(std::vector<int>& vec, int value) {
    int low = 0, high = vec.size();
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (vec[mid] >= value) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (low < vec.size() && vec[low] >= value) 
      return low;
    else
      return -1;
  }
};

int main() {
  std::vector<std::vector<int>> envelopes{
    {2, 2}, 
    {5, 4}, 
    {6, 7}, 
    {6, 5}, 
    {6, 3}, 
    {7, 6}, 
  };

  auto ans = Solution::maxEnvelopes(envelopes);

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
