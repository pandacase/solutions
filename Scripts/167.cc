#include <vector>
#include <iostream>
#include <string>
#include <cctype>

//! @brief 给你一个下标从 1 开始的整数数组numbers，该数组已按非递减顺序排列，
//! 请你从数组中找出满足相加之和等于目标数 target 的两个数。
//! 如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，
//! 则 1 <= index1 < index2 <= numbers.length。
//! 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标。
//! 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
//! 你所设计的解决方案必须只使用常量级的额外空间。
//! 
//! @details 
//! 2 <= numbers.length <= 3 * 104
//! -1000 <= numbers[i] <= 1000
//! numbers 按 非递减顺序 排列
//! -1000 <= target <= 1000
//! 仅存在一个有效答案
//! 
//! @example 
//! input:  numbers = [2,7,11,15], target = 9
//! output: [1,2]
//! 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
//! input:  numbers = [2,3,4], target = 6
//! output: [1,3]
//! 2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。
//! input: numbers = [-1,0], target = -1
//! output: [1,2]
//! -1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
//! 
//! @note
//! 
class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() -1;
    while (left < right) {
      if (numbers[left] + numbers[right] > target) 
        right -= 1;
      else if (numbers[left] + numbers[right] < target)
        left += 1;
      else break;
    }
    return {left + 1, right + 1};
  }
};

int main() {
  Solution sol;
  std::vector<int> numbers{2,3,4};
  auto ans = sol.twoSum(numbers, 6);

  for (auto a : ans)
    std::cout << a << std::endl;
}
