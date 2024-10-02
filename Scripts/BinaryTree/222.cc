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
//! 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//! 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，
//! 其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边
//! 的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
//! 
//! @details 
//! 树中节点的数目范围是[0, 5 * 104]
//! 0 <= Node.val <= 5 * 104
//! 题目数据保证输入的树是 完全二叉树
//! 
//! @example 
//! input:  root = [1,2,3,4,5,6]
//! output: 6
//! 
//! input:  root = []
//! output: 0
//! 
//! @note
//! 1. 普通二叉树的 dfs 计算方式
//! 2. 判断当前节点引导的子树是不是满二叉，是的话可以直接返回子树结点数，
//!    不是的话就往下遍历。
//!    由于完全二叉树的性质，左右子树中最多只有一个子树不是满二叉。
//!    所以总体的时间复杂度是 (logn)^2
//! 3. 二分查找 + 二进制编码 
//! 
class Solution {
public:
  //! @brief Method 1
  //! 
  // int 
  // countNodes_1(TreeNode* root) 
  // {
  //   if (!root) return 0;
  //   return countNodes_1(root->left) + countNodes_1(root->right) + 1;
  // }

  //! @brief Method 2
  //! 
  int
  countNodes(TreeNode* root)
  {
    if (!root) return 0;

    size_t l_depth{0}, r_depth{0};
    auto curr = root;
    while (curr->left) {
      l_depth += 1;
      curr = curr->left;
    }
    curr = root;
    while (curr->right) {
      r_depth += 1;
      curr = curr->right;
    }

    if (l_depth == r_depth)
      return (1 << (l_depth + 1)) - 1;
    else
      return countNodes(root->left) + countNodes(root->right) + 1;
  }

  //! @brief Method 3
  //! 
  int
  countNodes(TreeNode* root)
  {
    if (!root) return 0;

    int level = 0;
    auto curr = root;
    while (curr->left) {
      level += 1;
      curr = curr->left;
    }

    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (exists(root, level, mid)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return high;
  }

private:
  bool
  exists(TreeNode* root, int level, int index)
  {
    if (!level) return true; // 这个只对应单个根结点的特殊情况
    int bits = 1 << (level - 1);
    while (root && bits > 0) {
      if (!(bits & index)) {
        root = root->left;
      } else {
        root = root->right;
      }
      bits >>= 1;
    }
    return root != nullptr;
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20,
                       new TreeNode(15), new TreeNode(7)
    ));
  auto ans = sol.countNodes(root);

  // print link
  std::cout << ans << std::endl;
}
