
#include <string>
#include <unordered_map>

//! @brief 
//! Trie（前缀树）是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
//! 这一数据结构有多种应用场景，例如自动补全和拼写检查。
//! 
//! 实现 Trie 类，包含以下方法：
//! - Trie() 初始化前缀树对象。
//! - void insert(String word) 向前缀树中插入字符串 word。
//! - boolean search(String word) 如果字符串 word 在前缀树中，返回 true；
//!   否则，返回 false。
//! - boolean startsWith(String prefix) 如果之前已经插入的字符串 word 
//!   的前缀之一为 prefix，返回 true；否则，返回 false。
//!
//! @details 
//! 1 <= word.length, prefix.length <= 2000
//! word 和 prefix 仅由小写英文字母组成
//! insert、search 和 startsWith 调用次数总计不超过 3 * 10^4 次
//! 
//! @example 
//! 输入: 
//! ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
//! [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
//! 输出: 
//! [null, null, true, false, true, null, true]
//! 
//! 解释: 
//! Trie trie = new Trie();
//! trie.insert("apple");
//! trie.search("apple");   // 返回 True
//! trie.search("app");     // 返回 False
//! trie.startsWith("app"); // 返回 True
//! trie.insert("app");
//! trie.search("app");     // 返回 True
//! 
//! @note 
//!
class Trie {
private:
  struct TrieNode {
    bool _is_end;
    std::unordered_map<char, TrieNode*> _children;
    TrieNode() : _is_end(false) { };
  };

  TrieNode* root;

public:
  Trie() {
    root = new TrieNode;
  }
  
  void insert(std::string word) {
    auto node = root;
    for (char c : word) {
      if (!node->_children.count(c)) {
        node->_children[c] = new TrieNode();
      }
      node = node->_children[c];
    }
    node->_is_end = true;
  }
  
  bool search(std::string word) {
    auto node = root;
    for (char c : word) {
      if (!node->_children.count(c)) {
        return false;
      }
      node = node->_children[c];
    }
    return node->_is_end;
  }
  
  bool startsWith(std::string prefix) {
    auto node = root;
    for (char c : prefix) {
      if (!node->_children.count(c)) {
        return false;
      }
      node = node->_children[c];
    }
    return true;
  }
};
