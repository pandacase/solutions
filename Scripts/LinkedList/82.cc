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
//! 给定一个二叉搜索树的根节点 root ，和一个整数 k ，
//! 请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
//! 
//! @details 
//! 树中的节点数为 n 。
//! 1 <= k <= n <= 104
//! 0 <= Node.val <= 104
//! 
//! @example 
//! input:  [3,1,4,null,2], k = 1
//! output: 1
//! https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg
//! 
//! input:  root = [5,3,6,2,4,null,null,1], k = 3
//! output: 3
//! https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg
//! 
//! @note
//! 进阶一：如果你需要频繁地查找第 k 小的值，如何优化？
//! 用哈希表存储以每个结点为根的当前子树的结点总数。
//! 对于每个结点：
//! 左子树的节点数 n < k - 1 时，进入右子树
//! 左子树的节点数 n == k - 1 时，答案即为当前结点的 val
//! 左子树的节点数 n > k - 1 时，进入左子树
//! ↗️ 请查看 230+.c 
//! 
//! 进阶二：在频繁查找的基础上，树的结点还会频繁修改呢？
//! 这里的考点其实是把二叉搜索树改造成二叉平衡搜索树，比较复杂，这里省略
//! 
class Solution {
public:
  int 
  kthSmallest(TreeNode* root, int k) 
  {
    int value = -1;
    inorder(root, k, value);
    return value;
  }

  void
  inorder(TreeNode* root, int &k, int &value)
  {
    if (!root) return;
    
    inorder(root->left, k, value);
    if (value != -1)
      return;
    k -= 1;
    if (k == 0)
      value = root->val;
    inorder(root->right, k, value);
  }
};

static int a = 1;

int main() {
  Solution sol;
  auto root =     new TreeNode(5, 
      new TreeNode(4),         new TreeNode(7,
                        new TreeNode(6), new TreeNode(8)
      ));
  auto ans = sol.kthSmallest(root, 2);

  std::cout << ans << std::endl;
}