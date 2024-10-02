
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

//! @brief 
//! 给定一个字典 wordList，从单词 beginWord 到 endWord 的转换序列
//! 是一个按如下规则形成的序列：beginWord -> s1 -> s2 -> ... -> sk。
//! 
//! 1. 每对相邻的单词只差一个字母。
//! 2. 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意，beginWord 
//!    不需要在 wordList 中。
//! 3. sk == endWord。
//! 
//! 返回从 beginWord 到 endWord 的最短转换序列中的单词数目。
//! 如果不存在这样的转换序列，返回 0。
//! 
//! @details 
//! 1 <= beginWord.length <= 10
//! endWord.length == beginWord.length
//! 1 <= wordList.length <= 5000
//! wordList[i].length == beginWord.length
//! beginWord、endWord 和 wordList[i] 由小写英文字母组成
//! beginWord != endWord
//! wordList 中的所有字符串互不相同
//! 
//! @example 
//! input: beginWord = "hit", endWord = "cog", 
//!        wordList = ["hot","dot","dog","lot","log","cog"]
//! output: 5
//! 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog"，
//! 返回它的长度 5。
//! 
//! input: beginWord = "hit", endWord = "cog", 
//!        wordList = ["hot","dot","dog","lot","log"]
//! output: 0
//! 解释: endWord "cog" 不在字典中，所以无法进行转换。
//! 
//! @note 
//! 
class Solution {
private:
  std::unordered_map<std::string, size_t> _word_id;
  std::vector<std::vector<size_t>> _adj;
  size_t _node_num = 0;

public:
  int 
  ladderLength(
    std::string beginWord, std::string endWord, 
    std::vector<std::string>& wordList) 
  {
    addEdge(beginWord);
    for (auto& word : wordList)
      addEdge(word);
    if (!_word_id.count(endWord)) return 0;

    size_t begin_id = _word_id[beginWord];
    size_t end_id   = _word_id[endWord];

    std::vector<int> dist(_node_num, INT32_MAX);
    dist[begin_id] = 0;

    std::queue<size_t> queue;
    queue.push(begin_id);
    while (!queue.empty()) {
      auto curr = queue.front();
      queue.pop();

      if (curr == end_id)
        return dist[end_id] / 2 + 1;

      for (auto& next : _adj[curr]) {
        if (dist[next] == INT32_MAX) {
          dist[next] = dist[curr] + 1;
          queue.push(next);
        }
      }
    }

    return 0;
  }

private:
  void
  addWord(std::string& word)
  {
    if (!_word_id.count(word)) {
      _word_id[word] = _node_num++;
      _adj.emplace_back();
    }
  }

  void
  addEdge(std::string& word)
  {
    addWord(word);
    size_t id_u = _word_id[word];
    for (char& c : word) {
      char tmp = c;
      c = '*';
      
      addWord(word);
      size_t id_v = _word_id[word];
      _adj[id_u].push_back(id_v);
      _adj[id_v].push_back(id_u);
      
      c = tmp;
    }
  }
};


int
main()
{
  std::vector<std::string> wordList{
    "hot","dot","dog", "lot", "log", "cog"
  };

  Solution sol;
  sol.ladderLength("hit", "cog", wordList);
}
