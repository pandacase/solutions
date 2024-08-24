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
//! 给你一个二叉树的根节点 root ， 检查它是否轴对称。
//! 
//! @details 
//! 树中节点数目在范围 [1, 1000] 内
//! -100 <= Node.val <= 100
//! 
//! @example 
//! input:  root = [1,2,2,3,4,4,3]
//! output: true
//! 
//! @note
//! 
class Solution {
public:
  bool 
  isSymmetric(TreeNode* root) 
  {
    return isSymmetricNode(root->left, root->right);
  }

  bool
  isSymmetricNode(TreeNode* leftSide, TreeNode* rightSide)
  {
    if (leftSide == rightSide) return true;
    if (!leftSide || !rightSide) return false;

    if (leftSide->val == rightSide->val)
      return isSymmetricNode(leftSide->left, rightSide->right)
             && isSymmetricNode(leftSide->right, rightSide->left);
    else 
      return false;
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(1));
  auto ans = sol.isSymmetric(root);

  // print link
  std::cout << ans << std::endl;
}
