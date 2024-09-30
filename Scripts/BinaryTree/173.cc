
#include <iostream>
#include <stack>

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
//! 实现一个二叉搜索树迭代器类 BSTIterator，表示一个按中序遍历二叉搜索树(BST)的迭代器：
//! - BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 
//!   会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，
//!   且该数字小于 BST 中的任何元素。
//! - boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false。
//! - int next() 将指针向右移动，然后返回指针处的数字。
//! 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回
//! BST 中的最小元素。
//! 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，
//! BST 的中序遍历中至少存在一个下一个数字。
//! 
//! @details
//! - 树中节点的数目在范围 [1, 105] 内
//! - 0 <= Node.val <= 106
//! - 最多调用 105 次 hasNext 和 next 操作。
//! 
//! @example 
//! input: ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", 
//!         "hasNext", "next", "hasNext"]
//!        [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
//! output: [null, 3, 7, true, 9, true, 15, true, 20, false]
//!
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    this->pushLeft(root);
  }
  
  int next() {
    auto top = _node_stack.top();
    _node_stack.pop();

    this->pushLeft(top->right);

    return top->val;
  }
  
  bool hasNext() {
    return !_node_stack.empty();
  }

private:
  std::stack<TreeNode*> _node_stack;

  void pushLeft(TreeNode* root) {
    while (root) {
      _node_stack.push(root);
      root = root->left;
    }
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

