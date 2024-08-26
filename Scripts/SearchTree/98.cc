#include <string>
#include <vector>
#include <iostream>

#define MAX_INT 10e5 + 1

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
//! 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//! 有效 二叉搜索树定义如下：
//! 节点的左子树只包含 小于 当前节点的数。
//! 节点的右子树只包含 大于 当前节点的数。
//! 所有左子树和右子树自身必须也是二叉搜索树。
//! 
//! @details 
//! 树中节点数目范围在[1, 104] 内
//! -231 <= Node.val <= 231 - 1
//! 
//! @example 
//! input:  root = [2,1,3]
//! output: true
//! 
//! @note
//! 方法一：
//! 二叉搜索树性质：中序遍历得到的值序列是递增有序的。
//! 由于 val 的值访问是 INT32，所以这里必须使用 long long 传递 preVal
//! 以确保在到达*递增数组*的第一个值之后才开始更新 preVal。
//! 如果 preVal 的初值设置为INT32_MAX，遇到全是这个值的树，会误判为true
//! 
//! 另外，不可以将 long long 的值初始化为 INT32_MAX + 1
//! 这桑因为 INT32_MAX 会被编译器当作 int32_t 的类型进行处理，导致溢出
//! 
//! 方法二:
//! 递归验证二叉搜索树的几个定义。（ brief 中）
//! minNode 与 maxNode 用于确定上下界，
//! 进入左子树时将当前结点的值设置更新为上界；
//! 进入右子树时将当前结点的值设置更新为下界。
class Solution {
public:
  // Approach 1:
  bool 
  isValidBST(TreeNode* root) 
  {
    long long preVal = INT64_MAX;
    bool flag = true;
    inorder(root, preVal, flag);
    return flag;
  }

  void
  inorder(TreeNode* root, long long &preVal, bool &flag)
  {
    if (!root) return;
    
    inorder(root->left, preVal, flag);
    // 👇 this line should be before the flag updating.
    if (!flag) return;
    if (preVal != INT64_MAX)
      flag = root->val > preVal;
    preVal = root->val;
    inorder(root->right, preVal, flag);
  }

  // Approach 2:
  bool
  isValidBST_2(TreeNode* root) 
  {
    return isValidBST(root, nullptr, nullptr);
  }

  bool
  isValidBST(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
    if (!node) return true;

    // Check if current node violates the min/max constraint
    if (minNode && node->val <= minNode->val) return false;
    if (maxNode && node->val >= maxNode->val) return false;

    // Recursively check the subtrees with updated constraints
    return isValidBST(node->left, minNode, node) &&
           isValidBST(node->right, node, maxNode);
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(5, 
      new TreeNode(4),         new TreeNode(6,
                        new TreeNode(3), new TreeNode(7)
      ));
  auto ans = sol.isValidBST(root);

  std::cout << ans << std::endl;
}