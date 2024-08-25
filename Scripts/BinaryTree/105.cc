#include <string>
#include <vector>
#include <iostream>


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
//! 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的
//! 先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
//! 
//! @details 
//! 1 <= preorder.length <= 3000
//! inorder.length == preorder.length
//! -3000 <= preorder[i], inorder[i] <= 3000
//! preorder 和 inorder 均 无重复 元素
//! inorder 均出现在 preorder
//! preorder 保证 为二叉树的前序遍历序列
//! inorder 保证 为二叉树的中序遍历序列
//! 
//! @example 
//! input:  preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//! output: [3,9,20,null,null,15,7]
//! 
//! input:  preorder = [-1], inorder = [-1]
//! output: [-1]
//! 
//! @note
//! 
class Solution {
public:
  TreeNode* 
  buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
  {
    return buildTree(
      preorder, 0, inorder, 0, inorder.size());
  }

  TreeNode* 
  buildTree(
    std::vector<int>& preorder, int preBegin, 
    std::vector<int>& inorder, int inBegin,
    int length) 
  {
    if (length == 0) return nullptr;

    int value = preorder[preBegin];
    auto node = new TreeNode(value);

    int i = inBegin;
    for (; i < inBegin + length; ++i) {
      if (inorder[i] == value)
        break;
    }

    int leftLength = i - inBegin;
    int rightLength = inBegin + length - 1 - i;
    node->left = buildTree(
      preorder, preBegin + 1, 
      inorder, inBegin, 
      leftLength);
    node->right = buildTree(
      preorder, preBegin + leftLength + 1, 
      inorder, i + 1, 
      rightLength);

    return node;
  }
};


int main() {
  Solution sol;
  std::vector<int> pre{3,9,20,15,7};
  std::vector<int> in{9,3,15,20,7};
  auto ans = sol.buildTree(pre, in);

  // print link
  std::cout << ans << std::endl;
}
