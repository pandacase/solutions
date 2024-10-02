
#include <vector>
#include <queue>

//! @brief 
//! 给定 numCourses 门课程，课程编号从 0 到 numCourses - 1。你需要根据
//! prerequisites 数组中的先修条件确定学习顺序。
//! prerequisites[i] = [ai, bi] 表示在选修课程 ai 前必须先选修 bi。
//! 
//! 返回一个可以学完所有课程的顺序。如果不存在这样的顺序，返回空数组。
//! 
//! @details 
//! 1 <= numCourses <= 2000
//! 0 <= prerequisites.length <= numCourses * (numCourses - 1)
//! prerequisites[i].length == 2
//! 0 <= ai, bi < numCourses
//! ai != bi，且所有 [ai, bi] 互不相同。
//! 
//! @example 
//! input: numCourses = 2, prerequisites = [[1,0]]
//! output: [0,1]
//! 解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确
//! 的课程顺序为 [0,1]。
//! 
//! input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
//! output: [0,2,1,3]
//! 解释: 总共有 4 门课程。要学习课程 3，应该先完成课程 1 和 2，它们都应
//! 该在课程 0 之后。因此一个正确的课程顺序是 [0,1,2,3]，另一个顺序为
//! [0,2,1,3]。
//! 
//! input: numCourses = 1, prerequisites = []
//! output: [0]
//! 
class Solution {
public:
  std::vector<int> 
  findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) 
  {
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> in_degree(numCourses);

    for (auto& req : prerequisites) {
      adj[req[0]].push_back(req[1]);
      in_degree[req[1]] += 1;
    }

    std::queue<int> queue;
    std::vector<int> topo;
    for (int i = 0; i < numCourses; ++i)
      if (in_degree[i] == 0)
        queue.push(i);
    
    while (!queue.empty()) {
      int u = queue.front(); queue.pop();
      topo.push_back(u);

      for (auto v : adj[u]) {
        in_degree[v] -= 1;
        if (in_degree[v] == 0) {
          queue.push(v);
        }
      }
    }

    if (topo.size() != numCourses)
      topo.clear();
    else
      std::reverse(topo.begin(), topo.end());

    return topo;
  }
};