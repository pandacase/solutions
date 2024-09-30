
#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//! @brief 
//! 二叉树中的路径被定义为一条节点序列，
//! 序列中每对相邻节点之间都存在一条边。
//! 同一个节点在一条路径序列中至多出现一次。
//! 该路径至少包含一个节点，且不一定经过根节点。
//! 
//! 路径和是路径中各节点值的总和。
//! 
//! 给你一个二叉树的根节点 root，返回其最大路径和。
//! 
//! @details 
//! 树中节点数目范围是 [1, 3 * 10^4]。
//! -1000 <= Node.val <= 1000
//! 
//! @example 
//! input: root = [1,2,3]
//! output: 6
//! 解释: 最优路径是 2 -> 1 -> 3，路径和为 2 + 1 + 3 = 6。
//! 
//! input: root = [-10,9,20,null,null,15,7]
//! output: 42
//! 解释: 最优路径是 15 -> 20 -> 7，路径和为 15 + 20 + 7 = 42。
//! 
class Solution {
public:
  int 
  maxPathSum(TreeNode* root) 
  {
    int ans = INT32_MIN;
    traverse(root, ans);
    return ans;
  }

private:
  int
  traverse(TreeNode* root, int& maxSum) 
  {
    if (!root) return 0;
    int leftMax = std::max(traverse(root->left, maxSum), 0);
    int rightMax = std::max(traverse(root->right, maxSum), 0);
    int currSum = root->val + leftMax + rightMax;
    maxSum = std::max(maxSum, currSum);
    return root->val + std::max(rightMax, leftMax);
  }
};