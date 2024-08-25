#include <string>
#include <vector>
#include <iostream>
#include <queue>


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
   : val(x), left(left), right(right) {}
};

//! @brief 
//! 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
//! （即逐层地，从左到右访问所有节点）。
//! 
//! @details 
//! 树中节点数目在范围 [0, 2000] 内
//! -1000 <= Node.val <= 1000
//! 
//! @example 
//! input:  root = [3,9,20,null,null,15,7]
//! output: [[3],[9,20],[15,7]]
//! 
//! input:  root = [1]
//! output: [[1]]
//! 
//! @note
//!  
class Solution {
public:
  std::vector<std::vector<int>> 
  levelOrder(TreeNode* root) 
  {
    if (!root) return {};
    std::queue<TreeNode*> queue;
    queue.push(root);

    std::vector<std::vector<int>> ans;
    while (!queue.empty()) {
      int size = queue.size();
      ans.push_back(std::vector<int>());
      for (int i = 0; i < size; ++i) {
        auto curr = queue.front();
        ans.back().push_back(curr->val);
        queue.pop();

        if (curr->left)
          queue.push(curr->left);
        if (curr->right)
          queue.push(curr->right);
      }
    }
    return ans;
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20,
                       new TreeNode(15), new TreeNode(7)
    ));
  auto ans = sol.levelOrder(root);

  for (auto & vec : ans) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}