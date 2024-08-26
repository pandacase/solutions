#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


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
//! 给你二叉树的根结点 root ，请你将它展开为一个单链表：
//! 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中
//! 下一个结点，而左子指针始终为 null 。
//! 展开后的单链表应该与二叉树 前序遍历 顺序相同。
//! 
//! @details 
//! 树中结点数在范围 [0, 2000] 内
//! -100 <= Node.val <= 100
//! 
//! @example 
//! input:  root = [1,2,5,3,4,null,6]
//! output: [1,null,2,null,3,null,4,null,5,null,6]
//! ![](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)
//! 
//! input:  root = []
//! output: []
//! 
//! input:  root = [0]
//! output: [0]
//! 
//! @note
//! 先前序遍历，存入 vector，可在 O(n) 空间完成。
//! 
//! 不需要先进行一次遍历存储 vector 的方法：
//! 先前需要存起来是因为：
//! 直接在前序遍历的过程中修改指针会导致丢失原来的右子结点
//! 而前序遍历的后半部分递归是依赖于 root->right 的
//! 可以使用栈来模拟函数栈递归过程，每次从栈顶弹出一个结点后，
//! 依次入栈右子、左子（确保出栈顺序是左、右）
//! 这样便可以一边前序遍历一边修改结点的左右指针了。
//! 
//! 又或者，采用顺序完全相反的后序遍历：
//! right -> left -> root
//! 此时每访问到一个结点时，右结点一定已经访问过了
//! 所以可以直接进行指针处理，不会影响后序遍历的过程
//! 这种方法只需要 O(1) 就可以解决！
//! 
//! 最后，可以使用如下算法，也是 O(1) 解决
class Solution {
public:
  void 
  flatten(TreeNode* root) 
  {
    auto curr = root;
    while (curr) {
      if (curr->left) {
        auto leftChild = curr->left;
        auto preNode = leftChild;
        while (preNode->right)
          preNode = preNode->right;
        preNode->right = curr->right;
        curr->left = nullptr;
        curr->right = leftChild;
      }
      curr = curr->right;
    }
  }
};


int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20,
                       new TreeNode(15), new TreeNode(7)
    ));
  sol.flatten(root);
}
