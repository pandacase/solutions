#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

//! Another implementation for custom comparing.
struct Cmp {
  std::string custom_order;

  Cmp(const std::string& order) : custom_order(order) { }

  bool operator()(const std::string& s1, const std::string& s2) const {
    size_t n = std::min(s1.size(), s2.size());
    for (size_t i = 0; i < n; ++i) {
      size_t pos1 = custom_order.find(s1[i]);
      size_t pos2 = custom_order.find(s2[i]);
      if (pos1 != pos2) {
        return pos1 > pos2;
      }
    }
    return s1.size() > s2.size();
  }

  //! Usage
  void example() {
    std::vector<std::string> vec = {"apple", "boy", "cat", "dog"};
    std::string order = "abcdefghijklmnopqrstuvwxyz";
    Cmp cmp(order);
    // sort
    std::sort(vec.begin(), vec.end(), cmp);
    // heap
    std::priority_queue<std::string, std::vector<std::string>, Cmp> min_heap(cmp);
  }

};

//! @brief 
//! 按照一个给定的字典序，返回 vector<string> 中最大的 k 个字符串
//! 
class Solution {
public:
  std::vector<std::string>
  kLargestStr(
    std::vector<std::string>& strs, std::string custom_order, size_t k
  ) {
    int n = strs.size();
    if (k >= n) return strs;

    auto cmp = [custom_order](const std::string& s1, const std::string& s2) {
      size_t n = std::min(s1.size(), s2.size());
      for (size_t i = 0; i < n; ++i) {
        size_t pos1 = custom_order.find(s1[i]);
        size_t pos2 = custom_order.find(s2[i]);
        if (pos1 != pos2) {
          return pos1 > pos2;
        }
      }
      return s1.size() > s2.size();
    };

    std::priority_queue<
      std::string, 
      std::vector<std::string>, 
      decltype(cmp)
    > min_heap(cmp);

    for (auto& str : strs) {
      if (min_heap.size() < k)
        min_heap.push(str);
      else if (cmp(str, min_heap.top())) {
        min_heap.pop();
        min_heap.push(str);
      }
    }

    std::vector<std::string> ans;
    while (!min_heap.empty()) {
      ans.push_back(min_heap.top());
      min_heap.pop();
    }

    return ans;
  }

};

int main() {
  std::vector<std::string> vec = {
    "apple", "banana", "cherry", "avocado", "blueberry", "doggy", 
    "elaina", "panda", "latex", "maybe", "nvidia", "crazy", "for", "you"
    };
  std::string custom_order = "bacdefghijklmnopqrstuvwxyz";

  Solution sol;
  auto ans = sol.kLargestStr(vec, custom_order, 3);

  for (auto& str : ans) {
    std::cout << str << std::endl;
  }
}
