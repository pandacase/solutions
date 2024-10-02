
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

//! @brief 
//! 给定两个基因序列 start 和 end ，以及一个基因库 bank ，返回
//! 能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因
//! 变化，返回 -1。
//! 
//! 基因序列表示为一条由 8 个字符组成的字符串，每个字符是 'A'、'C'、
//! 'G'、'T' 中的一个字符。一次基因变化意味着基因序列中的一个字符发生
//! 了变化，且变化后的基因必须存在于给定的基因库 bank 中。
//! 
//! @details 
//! start.length == 8
//! end.length == 8
//! 0 <= bank.length <= 10
//! bank[i].length == 8
//! start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成。
//! 
//! @example 
//! input: start = "AACCGGTT", end = "AACCGGTA", 
//!        bank = ["AACCGGTA"]
//! output: 1
//! 解释: "AACCGGTT" --> "AACCGGTA" 是一次基因变化。
//! 
//! input: start = "AACCGGTT", end = "AAACGGTA", 
//!        bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
//! output: 2
//! 解释: "AACCGGTT" --> "AACCGGTA" --> "AAACGGTA" 共需要两次变化。
//! 
//! input: start = "AAAAACCC", end = "AACCCCCC", 
//!        bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
//! output: 3
//! 解释: "AAAAACCC" --> "AAAACCCC" --> "AAACCCCC" --> "AACCCCCC" 
//!       共需要三次变化。
//! 
//! @note 
//! 
class Solution {
private:
  using GeneStep = std::pair<std::string, size_t>;

public:
  int 
  minMutation(
    std::string startGene, std::string endGene, 
    std::vector<std::string>& bank) 
  {
    std::queue<GeneStep> queue;
    std::unordered_set<std::string> visited;
    queue.emplace(startGene, 0);
    visited.insert(startGene);

    while (!queue.empty()) {
      auto curr = queue.front(); 
      queue.pop();

      for (auto& gene : bank) {
        if (visited.count(gene)) continue;
        else if (distance(curr.first, gene) == 1) {
          if (gene == endGene)
            return curr.second + 1;
          visited.insert(gene);
          queue.emplace(gene, curr.second + 1);
        }
      }
    }

    return -1;
  }

private:
  size_t
  distance(const std::string& str1, const std::string& str2)
  {
    if (str1.length() != str2.length())
      throw std::invalid_argument(
        "Strings must be of the same length.");
    
    size_t dist = 0;
    for (size_t i = 0; i < str1.length(); ++i)
      if (str1[i] != str2[i])
        dist += 1;
    return dist;
  }
};


int
main()
{
  std::vector<std::string> bank{
    "AACCGGTA","AACCGCTA","AAACGGTA" 
  };

  Solution sol;
  sol.minMutation("AACCGGTT", "AAACGGTA", bank);
}