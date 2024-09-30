
#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_set>

//! @brief 
//! 在 vec 中找出所有的 pair<int, int>，
//! 当满足 vec 去掉这 2 个数之后整个数组的平均数仍然跟原来相同。
//! 
class Solution {
public:
  static std::vector<std::pair<int, int>>
  getPairs(std::vector<int>& vec) {
    int n = vec.size();
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    int average = sum / n;
    int double_average = average * 2;

    std::vector<std::pair<int, int>> ans;
    std::unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
      if (seen.count(double_average - vec[i])) {
        ans.emplace_back(vec[i], double_average - vec[i]);
      } else {
        seen.insert(vec[i]);
      }
    }

    return ans;
  }
};

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  auto ans = Solution::getPairs(vec);

  for (auto& [x, y] : ans) {
    std::cout << x << " " << y << std::endl;
  }
}
