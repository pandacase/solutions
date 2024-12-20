
#include <iostream>
#include <vector>
#include <string>

//! @brief 
//! 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//! 答案可以按任意顺序返回。数字到字母的映射与电话按键相同。
//! 注意数字 1 不对应任何字母。
//! 
//! @details 
//! 0 <= digits.length <= 4
//! digits[i] 是范围 ['2', '9'] 的一个数字。
//! 
//! @example 
//! input: digits = "23"
//! output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//! 
//! input: digits = ""
//! output: []
//! 
//! input: digits = "2"
//! output: ["a","b","c"]
//! 
class Solution {
public:
  std::vector<std::string> 
  letterCombinations(std::string digits) 
  {
    size_t n = digits.size();
    if (!n) return { };
    std::string curr_ans;
    std::vector<std::string> ans;
    letterCombinations(digits, 0, curr_ans, ans);
    return ans;
  }

private:
  void
  letterCombinations(
    std::string& digits,
    std::size_t curr_idx,
    std::string& curr_ans,
    std::vector<std::string>& ans
  ) {
    if (curr_idx == digits.size()) {
      ans.push_back(curr_ans);
      return;
    }
    size_t key = digits[curr_idx] - '0' - offset;
    for (auto ch : digit2char[key]) {
      curr_ans.push_back(ch);
      letterCombinations(digits, curr_idx + 1, curr_ans, ans);
      curr_ans.pop_back();
    }
  }

private:
  const size_t offset = 2;
  std::vector<std::vector<char>> digit2char {
    {'a', 'b', 'c'}, // idx 0 : digit 2 
    {'d', 'e', 'f'}, 
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
  };
};
