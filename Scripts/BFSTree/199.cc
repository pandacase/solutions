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
//! 给定一个二叉树的 根节点 root，想象自己站在它的右侧，
//! 按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//! 
//! @details 
//! 二叉树的节点个数的范围是 [0,100]
//! -100 <= Node.val <= 100 
//! 
//! @example 
//! input:  [1,2,3,null,5,null,4]
//! output: [1,3,4]
//! 
//! input:  [1,null,3]
//! output: [1,3]
//! 
//! input:  []
//! output: []
//! 
//! @note
//! 
class Solution {
public:
  std::vector<int> 
  rightSideView(TreeNode* root) 
  {
    if (!root) return {};
    std::queue<TreeNode*> queue;
    queue.push(root);

    std::vector<int> ans;
    while (!queue.empty()) {
      int size = queue.size();
      for (int i = 0; i < size; ++i) {
        auto curr = queue.front();
        if (i == size - 1)
          ans.push_back(curr->val);
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
  auto ans = sol.rightSideView(root);

  for (auto & a : ans)
    std::cout << a << " ";
  std::cout << std::endl;
}
