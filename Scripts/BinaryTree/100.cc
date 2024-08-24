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
//! 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//! 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//! 
//! @details 
//! 两棵树上的节点数目都在范围 [0, 100] 内
//! -104 <= Node.val <= 104
//! 
//! @note
//! 
class Solution {
public:
  bool 
  isSameTree(TreeNode* p, TreeNode* q) 
  {
    if (p == q) return true;
    else if (!p || !q) return false;

    if (p->val == q->val) 
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    else 
      return false;
  }
};


int main() {
  Solution sol;
  
  auto t1 =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20));
  
  auto t2 =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20));

  auto ans = sol.isSameTree(t1, t2);

  // print link
  std::cout << ans << std::endl;
}
