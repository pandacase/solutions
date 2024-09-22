#include <iostream>
#include <array>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<double> monster_angles;
  std::priority_queue<double> angle_diff;
  for (int i = 0; i < n; ++i) {
    double curr_angle;
    scanf("%f", curr_angle);
    for (auto angle : monster_angles) {
      angle_diff.push(std::abs(curr_angle - angle));
    }
    monster_angles.push_back(curr_angle);
  }
  if (angle_diff.empty()) {
    angle_diff.push(180.0);
  }

  double d = 1 / (2 * m) 
           + 1 / (2 * m) 
           - (180 - angle_diff.top()) / (360 * m * m );

}
