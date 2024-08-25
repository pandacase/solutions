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
//! 给定两个整数数组inorder和postorder，其中inorder是二叉树的中序遍历，
//! postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
//! 
//! @details 
//! 1 <= inorder.length <= 3000
//! postorder.length == inorder.length
//! -3000 <= inorder[i], postorder[i] <= 3000
//! inorder 和 postorder 都由 不同 的值组成
//! postorder 中每一个值都在 inorder 中
//! inorder 保证是树的中序遍历
//! postorder 保证是树的后序遍历
//! 
//! @example 
//! input:  inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//! output: [3,9,20,null,null,15,7]
//! 
//! input:  inorder = [-1], postorder = [-1]
//! output: [-1]
//! 
//! @note
//! 
class Solution {
public:
  TreeNode* 
  buildTree(std::vector<int>& inorder, std::vector<int>& postorder) 
  {
    return buildTree(
      postorder, 0, inorder, 0, inorder.size());
  }

  TreeNode* 
  buildTree(
    std::vector<int>& postorder, int postBegin, 
    std::vector<int>& inorder, int inBegin,
    int length) 
  {
    if (length == 0) return nullptr;

    int value = postorder[postBegin + length - 1];
    auto node = new TreeNode(value);

    int i = inBegin;
    for (; i < inBegin + length; ++i) {
      if (inorder[i] == value)
        break;
    }

    int leftLength = i - inBegin;
    int rightLength = inBegin + length - 1 - i;
    node->left = buildTree(
      postorder, postBegin, 
      inorder, inBegin, 
      leftLength);
    node->right = buildTree(
      postorder, postBegin + leftLength, 
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
