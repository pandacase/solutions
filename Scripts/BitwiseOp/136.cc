
#include <vector>
#include <iostream>


//! @brief 
//! 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 两次 。
//! 请你找出并返回那个只出现了一次的元素。
//! 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
//! 
//! @details 
//! 1 <= nums.length <= 3 * 104
//! -3 * 104 <= nums[i] <= 3 * 104
//! 除了某个元素只出现一次以外，其余每个元素均出现两次。
//! 
//! @note
//! 关于异或运算：
//! 1. 任何数和 0 做异或运算，结果仍然是原来的数，即 a ⊕ 0 = a。
//! 2. 任何数和其自身做异或运算，结果是 0，即 a ⊕ a = 0。
//! 3. 异或运算满足交换律和结合律
//! 
//! 所以，将全部数异或之后即得到了单独出现的数
class Solution {
public:
  int 
  singleNumber(std::vector<int>& nums) 
  {
    int res = 0;
    for (auto e: nums) res ^= e;
    return res;
  }
};


int main() {
  Solution sol;
  std::vector<int> nums{2, 2, 3};
  auto ans = sol.singleNumber(nums);

  // print link
  std::cout << ans << std::endl;
}
