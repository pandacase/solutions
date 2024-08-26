#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

//! Brief Description see 230.cc

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
   : val(x), left(left), right(right) {}
};

class MyBst {
public:
  MyBst()
  { }

  MyBst(TreeNode* root) 
  {
    _root = root;
    countNode(root);
  }

  int
  kthSmallest(int k) 
  {
    auto p = _root;

    while (p != nullptr) {
      int leftSub = _numOfNodes[p->left];
      if (leftSub < k - 1) {
        p = p->right;
        k -= leftSub + 1;
      } else if (leftSub > k - 1)
        p = p->left;
      else
        break;
    }
    return p->val;
  }

private:
  TreeNode* _root;
  std::unordered_map<TreeNode*, int> _numOfNodes;

  int
  countNode(TreeNode* root) 
  {
    if (!root) return 0;
    _numOfNodes[root] 
      = 1 + countNode(root->left) + countNode(root->right);
    return _numOfNodes[root];
  }
};

class Solution {
public:
  int 
  kthSmallest(TreeNode* root, int k) 
  {
    if (!isInitialized) {
      bst = MyBst(root);
      isInitialized = true;
    }
    return bst.kthSmallest(k);
  }

private:
  MyBst bst; // 这里需要 MyBst 有默认构造函数
  bool isInitialized = false;
};

int main() {
  Solution sol;
  auto root =     new TreeNode(1, 
            nullptr,       new TreeNode(2
      ));
  auto ans = sol.kthSmallest(root, 2);

  std::cout << ans << std::endl;
}
