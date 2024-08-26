#include <string>
#include <vector>
#include <iostream>

#define MAX_INT 1e5 + 1

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
//! 给你一个二叉搜索树的根节点root，返回树中任意两不同节点值之间的
//! 最小差值 。差值是一个正数，其数值等于两值之差的绝对值。
//! 
//! @details 
//! 树中节点的数目范围是 [2, 104]
//! 0 <= Node.val <= 105
//! 
//! @example 
//! input:  root = [4,2,6,1,3,null,null]
//! output: 1
//! 
//! input:  [1,0,48,null,null,12,49]
//! output: 1
//! 
//! @note
//! 二叉搜索树性质：中序遍历得到的值序列是递增有序的。
//! preVal 需要引用传值是确保每一轮计算时，preVal 都是上一轮遍历更新的值
//! 比如递增序列是 [4, 5, 7] （如 main 中所示）
//! 为了确保遍历到 5 时，preVal = 4，参数需要共用同一个 int。
//! 否则在 4 结点更新完 preVal 之后，这个值只能传递给 inorder(root->right)
//! 但是显然在从 4 结点返回到 5 结点时，preVal = 4 已经被弹出了栈
class Solution {
public:
  int 
  getMinimumDifference(TreeNode* root) 
  {
    int min = MAX_INT, preVal = -1;
    inorder(root, preVal, min);
    return min;
  }

  void
  inorder(TreeNode* root, int &preVal, int &min) {
    if (!root) return;
    inorder(root->left, preVal, min);
    if (preVal != -1)
      min = std::min(min, root->val - preVal);
    preVal = root->val;
    inorder(root->right, preVal, min);
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(5, 
      new TreeNode(4),         new TreeNode(7));
  auto ans = sol.getMinimumDifference(root);

  std::cout << ans << std::endl;
}