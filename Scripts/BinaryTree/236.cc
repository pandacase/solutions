
#include <unordered_set>
#include <unordered_map>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//! @brief 
//! 给定一个二叉树，找到该树中两个指定节点的最近公共祖先。
//! 
//! 最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共
//! 祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大
//! （一个节点也可以是它自己的祖先）。”
//! 
//! @details 
//! 树中节点数目在范围 [2, 105] 内。
//! -10^9 <= Node.val <= 10^9
//! 所有 Node.val 互不相同。
//! p != q 且 p 和 q 均存在于给定的二叉树中。
//! 
//! @example 
//! input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//! output: 3
//! 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
//! 
//! input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//! output: 5
//! 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。
//! 因为根据定义最近公共祖先节点可以为节点本身。
//! 
//! input: root = [1,2], p = 1, q = 2
//! output: 1
//! 解释: 节点 1 和节点 2 的最近公共祖先是节点 1。
//!
//! @note
//! 方法一：最简单的先存储父结点之后推导
//! 方法二：见注释
//!
class Solution {
public:
  TreeNode* 
  lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
  {
    std::unordered_map<TreeNode*, TreeNode*> father;
    father[root] = nullptr;
    this->traverse(father, root);
    
    std::unordered_set<TreeNode*> seen;
    while (p) {
      seen.insert(p);
      p = father[p];
    }
    while (q) {
      if (seen.count(q))
        return q;
      q = father[q];
    }
    return nullptr;
  }

  TreeNode*
  lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (!root || root == p || root == q) return root;
    auto left = lowestCommonAncestor_2(root->left, p, q);
    auto right = lowestCommonAncestor_2(root->right, p, q);
    if (!left) return right; // 这 2 行非常关键，将所有匹配不到 p q 的叶子节点
    if (!right) return left; // 向上传染为空结点
    return root; // 包含 p/q 的左右子树最终在这里相遇
  }

private:
  void
  traverse(
    std::unordered_map<TreeNode*, TreeNode*>& father, 
    TreeNode* root
  ) {
    if (!root)
      return;
    if (root->left)
      father[root->left] = root;
    if (root->right)
      father[root->right] = root;
    
    traverse(father, root->right);
    traverse(father, root->left);
  }
};


int
main()
{
  return 0;
}
