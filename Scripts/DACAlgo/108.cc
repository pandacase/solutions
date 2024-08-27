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
//! 给你一个整数数组 nums ，其中元素已经按 升序 排列，
//! 请你将其转换为一棵 平衡 二叉搜索树。
//! 
//! @details 
//! 1 <= nums.length <= 104
//! -104 <= nums[i] <= 104
//! nums 按 严格递增 顺序排列
//! 
//! @example 
//! input:  nums = [-10,-3,0,5,9]
//! output: [0,-3,9,-10,null,5] or 0,-10,5,null,-3,null,9]
//! 
//! input:  nums = [1,3]
//! output: [3,1] or [1,null,3]
//! 
//! @note
//! 
class Solution {
public:
  TreeNode* 
  sortedArrayToBST(std::vector<int>& nums) 
  {
    if (nums.empty()) return nullptr;
    return buildBST(nums, 0, nums.size() - 1);
  }

private:
  TreeNode* 
  buildBST(const std::vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums{1, 3};
  auto ans = sol.sortedArrayToBST(nums);

  std::cout << ans << std::endl;
}