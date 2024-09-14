#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  std::cin >> t;
  if (t == 0) return 0;

  while (t--) {
    int n; scanf("%d", &n);
    std::vector<std::pair<bool, int>> nodes(n + 1);
    nodes[1] = {true, 0};
    // read all edge
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      if (nodes[u].first) {
        nodes[u].second += 1;
        nodes[v].first = true;
      } else if (nodes[v].first) {
        nodes[v].second += 1;
        nodes[u].first = true;
      }
    }

    // compute result
    std::unordered_map<int, int> cnt;
    for (int i = 1; i <= n; ++i) {
      cnt[nodes[i].second] += 1;
    }
    int res = 0;
    for (auto [key, num] : cnt) {
      // std::cout << key << " " << num << std::endl;
      res += (num * (num - 1)) / 2;
    }
    std::cout << res << std::endl;
  }
  return 0;
}
