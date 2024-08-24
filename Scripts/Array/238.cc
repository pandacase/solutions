#include <vector>
#include <iostream>

//! @brief 给你一个整数数组 nums，返回数组 answer ，其中 answer[i] 
//! 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//! 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//!
//! @details
//! 2 <= nums.length <= 105
//! -30 <= nums[i] <= 30
//! 保证数组中任意元素的全部前缀元素和后缀的乘积都在32位整数范围内
//! 
//! @example 
//! input:  nums = [1,2,3,4]
//! output: [24,12,8,6]
//! input:  nums = [-1,1,0,-3,3]
//! output: [0,0,9,0,0]
//!  
class Solution {
public:
  //! @note 第一版，O(n) 时间，2n 内存
  // std::vector<int> 
  // productExceptSelf(std::vector<int>& nums) 
  // {
  //   int size = nums.size();

  //   std::vector<int> forwardCumuProduct(size, 1);
  //   for (int i = 0; i < size; ++i) {
  //     if (i == 0) {
  //       forwardCumuProduct[i] = 1;
  //     } else {
  //       forwardCumuProduct[i] 
  //         = forwardCumuProduct[i - 1] * nums[i - 1];
  //     }
  //   }
    
  //   std::vector<int> backwardCumuProduct(size, 1);
  //   for (int i = size - 1; i >= 0; --i) {
  //     if (i == size - 1) {
  //       backwardCumuProduct[i] = 1;
  //     } else {
  //       backwardCumuProduct[i] 
  //         = backwardCumuProduct[i + 1] * nums[i + 1];
  //     }
  //   }

  //   for (int i = 0; i < size; ++i) {
  //     forwardCumuProduct[i] *= backwardCumuProduct[i];
  //   }

  //   return forwardCumuProduct;
  // }

  //! @note 第二版，O(n) 时间，n 内存
  std::vector<int> 
  productExceptSelf(std::vector<int>& nums) 
  {
    int size = nums.size();

    std::vector<int> ans(size, 1);
    int forwardIdx = 0, backwardIdx = size - 1;
    int forwardProduct = 1, backwardProduct = 1;
    for (int i = 0; i < size; ++i) {
      if (i > 0) {
        forwardProduct *= nums[forwardIdx - 1];
        backwardProduct *= nums[backwardIdx + 1];
      }
      ans[forwardIdx] *= forwardProduct;
      ans[backwardIdx] *= backwardProduct;
      ++forwardIdx;
      --backwardIdx;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums{1,2,3,4};
  auto ans = sol.productExceptSelf(nums);

  for (auto &num : ans) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}