#include <iostream>
#include <array>
#include <queue>

int main() {
  int n;
  std::cin >> n;
  
  std::array<int, 10> scores{0};
  for (int i = 0; i < n; ++i) {
    size_t played_cnt = 0;
    std::queue<int> votes;
    for (int j = 0; j < 10; ++j) {
      int vote;
      scanf("%d", &vote);
      if (vote == 1) {
        played_cnt += 1;
      } else if (vote == 2) {
        played_cnt += 1;
        votes.push(j/* game ID - 1 */);
      }
    }

    if (played_cnt >= 3 && votes.size() <= 5 
        && votes.size() <= played_cnt - 2) {
      while (!votes.empty()) {
        scores[votes.front()] += 1;
        votes.pop();
      }
    }
  }

  std::vector<int> max_score_IDs;
  int max_score = 0;
  for (int i = 0; i < 10; ++i) {
    if (scores[i] > max_score) {
      max_score_IDs.clear();
      max_score = scores[i];
      max_score_IDs.push_back(i + 1/* game ID */);
    } else if (scores[i] == max_score) {
      max_score_IDs.push_back(i + 1/* game ID */);
    }
  }

  for (auto id : max_score_IDs) {
    std::cout << id << " ";
  }
}
