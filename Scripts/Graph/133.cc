
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

class Node {
public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

//! @brief 
//! 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
//! 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
//! 测试用例格式：
//! 简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），
//! 第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。
//! 邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
//! 给定节点将始终是图中的第一个节点（值为1）。
//! 你必须将给定节点的拷贝作为对克隆图的引用返回。
//! 
//! @details 
//! 这张图中的节点数在 [0, 100] 之间。
//! 1 <= Node.val <= 100
//! 每个节点值 Node.val 都是唯一的，
//! 图中没有重复的边，也没有自环。
//! 图是连通图，你可以从给定节点访问到所有节点。
//! 
//! @note
//! Using BFS
//!
class Solution {
public:
  Node* 
  cloneGraph(Node* node) 
  {
    if (node == nullptr)
      return node;

    std::queue<Node*> helper;
    std::unordered_map<Node*, Node*> ori2copy;
    
    helper.push(node);
    ori2copy[node] = new Node(node->val);

    while (!helper.empty()) {
      auto curr = helper.front();
      helper.pop();
      
      for (auto& nei : curr->neighbors) {
        if (!ori2copy.count(nei)) {
          ori2copy[nei] = new Node(nei->val);
          helper.push(nei);
        }
        ori2copy[curr]->neighbors.push_back(ori2copy[nei]);
      }
    }
    return ori2copy[node];
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
