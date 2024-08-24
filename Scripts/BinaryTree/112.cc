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
//! 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
//! 判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值
//! 相加等于目标和 targetSum。如果存在，返回true；否则，返回false。
//! 叶子节点 是指没有子节点的节点。
//! 
//! @details 
//! 树中节点的数目在范围 [0, 5000] 内
//! -1000 <= Node.val <= 1000
//! -1000 <= targetSum <= 1000
//! 
//! @example 
//! input:  root = [5,4,8,11,null,13,4,7,2,null,null,null,1], 
//!         targetSum = 22
//! output: true
//! 路径：5->4->11->2
//! 
//! input:  root = [1,2,3], 
//!         targetSum = 5
//! output: false
//! 
//! @note
//! 所有到达叶子结点的路径中，只要有 1 个 true 就满足条件。
class Solution {
public:
  bool 
  hasPathSum(TreeNode* root, int targetSum) 
  {
    if (!root) return false;
    if (root->left == nullptr && root->right == nullptr)
      return targetSum == root->val;

    return hasPathSum(root->left, targetSum - root->val)
           || hasPathSum(root->right, targetSum - root->val);
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(1, 
      new TreeNode(2),         new TreeNode(3));
  auto ans = sol.hasPathSum(root, 1);

  // print link
  std::cout << ans << std::endl;
}
