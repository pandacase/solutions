#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <queue>

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
//! 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历。
//! （即先从左往右，再从右往左进行下一层遍历，以此类推，
//! 层与层之间交替进行）。
//! 
//! @details 
//! 树中节点数目在范围 [0, 2000] 内
//! -100 <= Node.val <= 100
//! 
//! @example 
//! input:  root = [3,9,20,null,null,15,7]
//! output: [[3],[20,9],[15,7]]
//! 
//! input:  root = [1]
//! output: [[1]]
//! 
//! @note
//! 也可以使用 algorithm 中的 std::reverse()
class Solution {
public:
  std::vector<std::vector<int>> 
  zigzagLevelOrder(TreeNode* root) 
  {
    if (!root) return {};
    std::deque<TreeNode*> deque;
    deque.push_back(root);

    std::vector<std::vector<int>> ans;
    int direction = 1;
    while (!deque.empty()) {
      int size = deque.size();
      ans.push_back(std::vector<int>());
      for (int i = 0; i < size; ++i) {
        TreeNode* curr;
        if (direction > 0) {
          curr = deque.front();
          deque.pop_front();
          if (curr->left)
            deque.push_back(curr->left);
          if (curr->right)
            deque.push_back(curr->right);
        } else {
          curr = deque.back();
          deque.pop_back();
          if (curr->right)
            deque.push_front(curr->right);
          if (curr->left)
            deque.push_front(curr->left);
        }
        ans.back().push_back(curr->val);
      }
      direction = -direction;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  auto root =     new TreeNode(3, 
      new TreeNode(9),         new TreeNode(20,
                       new TreeNode(15), new TreeNode(7)
    ));
  auto ans = sol.zigzagLevelOrder(root);

  for (auto & vec : ans) {
    for (auto & a : vec) 
      std::cout << a << " ";
    std::cout << std::endl;
  }
}