#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


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
//! 给定一个二叉树 root ，返回其最大深度。
//! 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
//! 你应当 保留 两个分区中每个节点的初始相对位置。
//! 
//! @details 
//! 树中节点的数量在 [0, 10^4] 区间内。
//! -100 <= Node.val <= 100
//! 
//! @example 
//! input:  root = [3,9,20,null,null,15,7]
//! output: 3
//! 
//! input:  root = [1,null,2]
//! output: 2
//! 
//! @note
//! 
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if(!root) 
      return 0;
    else 
      return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20,
                       new TreeNode(15), new TreeNode(7)
    ));
  auto ans = sol.maxDepth(root);

  // print link
  std::cout << ans << std::endl;
}
