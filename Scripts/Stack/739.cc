
#include <vector>
#include <stack>

//! @brief 
//! 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer，
//! 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
//! 如果气温在这之后都不会升高，请在该位置用 0 来代替。
//! 
//! @details
//! 1 <= temperatures.length <= 105
//! 30 <= temperatures[i] <= 100
//! 
//! @example 
//! input:  temperatures = [73,74,75,71,69,72,76,73]
//! output: [1,1,4,2,1,1,0,0]
//! 
//! input:  temperatures = [30,40,50,60]
//! output: [1,1,1,0]
//! 
//! 
class Solution {
public:
  std::vector<int> 
  dailyTemperatures(std::vector<int>& temperatures) 
  {
    int n = temperatures.size();
    std::stack<std::pair<int, int>> desc_temp;
    
    std::vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; ++i) {
      if (temperatures[i + 1] > temperatures[i]) {
        ans[i] = 1;
        while (!desc_temp.empty() &&
            desc_temp.top().first < temperatures[i + 1]) {
          auto prev_idx = desc_temp.top().second;
          ans[prev_idx] = i + 1 - prev_idx;
          desc_temp.pop();
        }
      } else {
        desc_temp.emplace(temperatures[i], i);
      }
    }

    return ans;
  }
};