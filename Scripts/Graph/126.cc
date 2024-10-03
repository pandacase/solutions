
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

//! @brief 
//! 按字典 wordList 完成从单词 beginWord 到单词 endWord 的转换。转换
//! 序列是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，
//! 并且每对相邻的单词之间仅有单个字母不同。
//! 
//! @details 
//! - 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中
//!   的单词。
//! - beginWord 不必是字典 wordList 中的单词。
//! - sk == endWord
//! 
//! @example 
//! input: beginWord = "hit", endWord = "cog", wordList = 
//!        ["hot","dot","dog","lot","log","cog"]
//! output: [["hit","hot","dot","dog","cog"],
//!          ["hit","hot","lot","log","cog"]]
//! 解释: 存在 2 种最短的转换序列。
//! 
//! input: beginWord = "hit", endWord = "cog", wordList = 
//!        ["hot","dot","dog","lot","log"]
//! output: []
//! 解释: endWord "cog" 不在字典 wordList 中，所以不存在符合要求的
//! 转换序列。
//! 
//! @note 
//! 1 <= beginWord.length <= 5
//! endWord.length == beginWord.length
//! 1 <= wordList.length <= 500
//! wordList[i].length == beginWord.length
//! beginWord、endWord 和 wordList[i] 由小写英文字母组成。
//! beginWord != endWord
//! wordList 中的所有单词互不相同。
//! 
//! @note 
//! 
class Solution {
private:
  std::unordered_map<std::string, size_t> _word2id;
  std::vector<std::string> _id2word;
  std::vector<std::vector<size_t>> _adj;

public:
  std::vector<std::string> 
  findLadders(
    std::string beginWord, std::string endWord, 
    std::vector<std::string>& wordList) 
  {
    addEdge(beginWord);
    for (auto& word : wordList)
      addEdge(word);
    if (!_word2id.count(endWord)) return {};

    size_t begin_id = _word2id[beginWord];
    size_t end_id   = _word2id[endWord];

    std::vector<int> prev(_id2word.size() - 1, -1);
    prev[begin_id] = 0;

    std::queue<size_t> queue;
    queue.push(begin_id);
    while (!queue.empty()) {
      auto curr_id = queue.front();
      queue.pop();

      if (curr_id == end_id) {
        std::vector<std::string> ans;
        bool flag;
        getPath(ans, prev, curr_id, flag);
        return ans;
      }

      for (auto& next : _adj[curr_id]) {
        if (prev[next] == -1) {
          prev[next] = curr_id;
          queue.push(next);
        }
      }
    }

    return {};
  }

private:
  void
  getPath(
    std::vector<std::string>& ans, 
    std::vector<int>& prev, size_t id,
    bool& flag)
  {
    if (id == 0) {
      // begin word
      ans.push_back(_id2word[0]); 
      flag = false;
    } else {
      getPath(ans, prev, prev[id], flag);
      if (flag)
        ans.push_back(_id2word[id]);
      flag = !flag;
    }
  }

  void
  addWord(std::string& word)
  {
    if (!_word2id.count(word)) {
      _id2word.emplace_back(word);
      _word2id[word] = _id2word.size() - 1;
      _adj.emplace_back();
    }
  }

  void
  addEdge(std::string& word)
  {
    addWord(word);
    size_t id_u = _word2id[word];
    for (char& c : word) {
      char tmp = c;
      c = '*';
      
      addWord(word);
      size_t id_v = _word2id[word];
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
  auto ans = sol.findLadders("hit", "cog", wordList);

  for (auto& str : ans) 
    std::cout << str << std::endl;
}
