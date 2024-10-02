
#include <vector>
#include <queue>
#include <iostream>

//! @brief 
//! 判断是否可以完成所有课程的学习。
//! 
//! 给定 numCourses 门课程，课程编号为 0 到 numCourses - 1。
//! 在选修某些课程之前需要先修课程。先修课程以数组 prerequisites 给出，
//! 其中 prerequisites[i] = [ai, bi] 表示如果要学习课程 ai，必须先学习课程 bi。
//! 
//! @details 
//! 输入条件：
//! - 1 <= numCourses <= 2000
//! - 0 <= prerequisites.length <= 5000
//! - prerequisites[i].length == 2
//! - 0 <= ai, bi < numCourses
//! - prerequisites[i] 中的所有课程对互不相同。
//! 
//! 返回值：
//! 如果可以完成所有课程，返回 true；否则返回 false。
//! 
//! @example 
//! input: numCourses = 2, prerequisites = [[1,0]]
//! output: true
//! 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。这是可能的。
//! 
//! input: numCourses = 2, prerequisites = [[1,0],[0,1]]
//! output: false
//! 解释：学习课程 1 之前需要先完成课程 0，但学习课程 0 之前也必须完成课程 1，
//! 这是不可能的循环依赖。
//! 
//! @note
//! 当前用的是经典的拓扑排序解法，//TODO 还可以用 dfs？
//! 
class Solution {
public:
  bool 
  canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) 
  {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> in_degree(numCourses);

    for (auto& req : prerequisites) {
      adj[req[0]].push_back(req[1]);
      in_degree[req[1]] += 1;
    }

    std::queue<int> queue;
    for (int i = 0; i < numCourses; ++i)
      if (in_degree[i] == 0)
        queue.push(i);
    
    int cnt = 0;
    while (!queue.empty()) {
      int u = queue.front(); queue.pop();
      cnt += 1;

      for (auto v : adj[u]) {
        in_degree[v] -= 1;
        if (in_degree[v] == 0) {
          queue.push(v);
        }
      }
    }

    return cnt == numCourses;
  }
};


int main() {

  //! 0  
  // std::cout << ans << std::endl;

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
