#include <string>
#include <vector>
#include <iostream>
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
//! 给定一个非空二叉树的根节点 root, 以数组的形式返回每一层节点的平均值。
//! 与实际答案相差 10^-5 以内的答案可以被接受。
//! 
//! @details 
//! 树中节点数量在 [1, 104] 范围内
//! -231 <= Node.val <= 231 - 1
//! 
//! @example 
//! input:  root = [3,9,20,null,null,15,7]
//! output: [3.00000,14.50000,11.00000]
//! 
//! input:  root = [3,9,20,15,7,null,null]
//! output: [3.00000,14.50000,11.00000]
//! 
//! @note
//! 除了用 nullptr 分割层，也可以在每轮遍历开始前就记录 queue.size()
//! 这样还可以节省对 cnt 的维护！
class Solution {
public:
  std::vector<double> 
  averageOfLevels(TreeNode* root) 
  {
    std::queue<TreeNode*> queue;
    queue.push(root);
    queue.push(nullptr);

    double sum = 0; int cnt = 0;
    std::vector<double> ans;
    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        auto curr = queue.front();
        sum += curr->val;
        cnt += 1;
        queue.pop();

        if (curr->left)
          queue.push(curr->left);
        if (curr->right)
          queue.push(curr->right);

        if (queue.front() == nullptr)
          queue.push(nullptr);
      } else {
        queue.pop();
        if (cnt > 0)
          ans.push_back(sum / cnt);
        sum = 0; cnt = 0;
      }
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
  auto ans = sol.averageOfLevels(root);

  for (auto & a : ans)
    std::cout << a << " ";
  std::cout << std::endl;
}
