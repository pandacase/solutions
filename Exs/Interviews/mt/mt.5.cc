#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  std::vector<std::vector<int>> tags(3, std::vector<int>(n, 0));
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &tags[i][j]);
  
  std::vector<int> idx;
  std::vector<std::queue<std::pair<int, int>>> tag_queue(m + 1);
  std::vector<int> max_costs(m + 1, INT32_MIN);
  for (int i = 0; i < n; ++i) {
    
    tag_queue[tags[0][i]].emplace(tags[1][i], tags[2][i]);
    max_costs[tags[0][i]] 
      = std::max(max_costs[tags[0][i]], (tags[1][i] - tags[2][i]));
  }

  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    if (!tag_queue[i].empty()) {
      bool geted = false;
      while (!tag_queue[i].empty()) {
        auto pair = tag_queue[i].front();
        tag_queue[i].pop();
        if (pair.first - pair.second == max_costs[i] && !geted) {
          geted = true;
          ans += pair.first;
        } else {
          ans += pair.second;
        }
      }
    }
  }

  printf("%d\n", ans);
}
