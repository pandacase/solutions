#include <vector>
#include <iostream>
#include <string>
#include <cctype>

#include <unordered_map>

//! @brief 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//! 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变
//! 剩余字符相对位置形成的新字符串。
//!（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
//! 
//! @details 
//! 0 <= s.length <= 100
//! 0 <= t.length <= 10^4
//! 两个字符串都只由小写字符组成。
//! 
//! @example 
//! input:  s = "abc", t = "ahbgdc"
//! output: true
//! input:  s = "axc", t = "ahbgdc"
//! output: false
//! 
//! @note
//! ⚠️如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，
//! 你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
//! 💡首先预处理 t 得到一个 `字符->有序下标列表` 的哈希表
//! 最后在查询众多 s 时，通过二分查找来确定 s 中的字符在有序列表中是否存在
//! 大于当前下标的
class Solution {
public:
  bool 
  isSubsequence(std::string s, std::string t) 
  {
    int sSize = s.size(), tSize = t.size();
    int sIdx = 0, tIdx = 0;
    for (; tIdx < tSize; ++tIdx) {
      if (s[sIdx] == t[tIdx])
        sIdx += 1;
      if (sIdx == sSize)
        break;
    }
    return sIdx == sSize;
  }

  std::vector<bool> 
  isSubsequence(std::vector<std::string> ss, std::string t) 
  {
    int tSize = t.size();
    // preprocess t
    std::unordered_map<char, std::vector<int>> hash;
    for (int i = 0; i < tSize; ++i) {
      char ch = t[i];
      if (hash.count(ch) == 0) {
        hash[ch] = std::vector<int>(1, i);
        hash[ch].reserve(100);
      }
      else 
        hash[ch].push_back(i);
    }

    // process ss
    int ssSize = ss.size();
    std::vector<bool> ans(ssSize, true);
    for (int i = 0; i < ssSize; ++i) {
      std::string s = ss[i];
      int sSize = s.size();
      int latestIdx = -1;
      for (int j = 0; j < sSize; ++j) {
        char ch = s[j];
        latestIdx = binarySearch(latestIdx, hash[ch]);
        if (latestIdx == -1) {
          ans[i] = false;
          break;
        }
      }
    }

    return ans;
  }

  //! @brief find a integer in `list` that *just* greater than `target`
  //! 
  //! @return -1 if not found
  int 
  binarySearch(const int& target, const std::vector<int>& list) 
  {
    int left = 0, right = list.size() - 1;
    int res = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (list[mid] > target) {
        res = list[mid];
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  auto ans = sol.isSubsequence(
    std::vector<std::string>{
      "abc", 
      "axc", 
      "ax", 
      "awe",
      ""},
    "ahbgdcxcv"
  );

  for (auto a : ans)
    std::cout << a << std::endl;
}
