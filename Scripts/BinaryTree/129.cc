
#include <vector>

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
//! 给你一个二叉树的根节点 root，树中每个节点都存放有一个 0 到 9 之
//! 间的数字。每条从根节点到叶节点的路径都代表一个数字。
//! 
//! 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123。
//! 计算从根节点到叶节点生成的所有数字之和。
//! 
//! 叶节点是指没有子节点的节点。
//! 
//! @details 
//! 树中节点的数目在范围 [1, 1000] 内。
//! 0 <= Node.val <= 9
//! 树的深度不超过 10。
//! 
//! @example 
//! input: root = [1,2,3]
//! output: 25
//! 解释: 从根到叶子节点路径 1->2 代表数字 12，
//! 从根到叶子节点路径 1->3 代表数字 13。
//! 因此，数字总和 = 12 + 13 = 25。
//! 
//! input: root = [4,9,0,5,1]
//! output: 1026
//! 解释: 从根到叶子节点路径 4->9->5 代表数字 495，
//! 从根到叶子节点路径 4->9->1 代表数字 491，
//! 从根到叶子节点路径 4->0 代表数字 40。
//! 因此，数字总和 = 495 + 491 + 40 = 1026。
//! 
class Solution {
public:
  int 
  sumNumbers(TreeNode* root) 
  {
    std::vector<int> results;
    traverse(root, 0, results);
    int ans = 0;
    for (auto res : results)
      ans += res;
    return ans;
  }

private:
  void
  traverse(TreeNode* root, int value, std::vector<int>& results)
  {
    if (!root)  return;
    value = value * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      results.push_back(value);
      return;
    }
    traverse(root->left, value, results);
    traverse(root->right, value, results);
  }
};