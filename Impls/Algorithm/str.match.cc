
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
  size_t
  bf(std::string text, std::string pattern)
  {
    size_t n = text.size();
    size_t m = pattern.size();

    for (size_t i = 0; i <= n - m; ++i) {
      for (size_t j = 0; j < m; ++j) {
        if (text[i + j] != pattern[j])
          break;
        if (j == m - 1)
          return i;
      }
    }
    return std::string::npos;
  }


public:
  size_t
  kmp(std::string text, std::string pattern)
  {
    size_t n = text.size();
    size_t m = pattern.size();
    auto next = get_nexts(pattern);

    size_t j = 0;
    for (size_t i = 0; i < n; ++i) {
      while (j > 0 && text[i] != pattern[j])
        j = next[j - 1] + 1;

      if (text[i] == pattern[j])
        ++j;
      
      if (j == m)
        return i - m + 1;
    }
    return std::string::npos;
  }

private:
  std::vector<int>
  get_nexts(std::string pattern)
  {

  }
};

