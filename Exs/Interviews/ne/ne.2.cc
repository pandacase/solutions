#include <iostream>
#include <array>
#include <queue>
#include <unordered_set>
using namespace std;

int find_op(std::vector<int>& nodes, int key) {
  if (key == nodes[key]) {
    return key;
  } else {
    nodes[key] = find_op(nodes, nodes[key]);
    return nodes[key];
  }
}

void union_op(std::vector<int>& nodes, int x, int y) {
  nodes[find_op(nodes, x)] = find_op(nodes, y);
}

int main() {
  int N, M, T;
  std::cin >> N >> M >> T;

  // union-find set
  std::vector<int> nodes(N);
  for (int i = 0; i < N; ++i) {
    nodes[i] = i;
  }
  // adj vector
  std::vector<std::unordered_set<int>> adj_vec(N);

  // record triangle
  for (int i = 0; i < M; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    union_op(nodes, x, y);
    union_op(nodes, y, z);
    union_op(nodes, z, x);
    adj_vec[x].insert(y); adj_vec[x].insert(z);
    adj_vec[y].insert(z); adj_vec[y].insert(x);
    adj_vec[z].insert(x); adj_vec[z].insert(y);
  }

  // testing
  for (int i = 0; i < T; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (find_op(nodes, x) == find_op(nodes, y)) {
      if (adj_vec[x].count(y)) {
        printf("1\n");
      } else {
        printf("2\n");
      }
    } else {
      printf("3\n");
    }
  }
}

