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
//! 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//! 
//! @details 
//! 树中节点数目范围在 [0, 100] 内
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
  TreeNode* 
  invertTree(TreeNode* root) 
  {
    if (!root) return nullptr;

    auto leftPtr = root->left;
    auto rightPtr = root->right;
    root->left = invertTree(rightPtr);
    root->right = invertTree(leftPtr);

    return root;
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20));
  auto ans = sol.invertTree(root);

  // print link
  std::cout << ans << std::endl;
}
