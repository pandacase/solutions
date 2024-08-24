#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <memory>

struct DListNode {
  int key, val;
  std::shared_ptr<DListNode> prev;
  std::shared_ptr<DListNode> next;
  DListNode(
    int _key, 
    int _value, 
    std::shared_ptr<DListNode> _prev = nullptr, 
    std::shared_ptr<DListNode> _next = nullptr
  ) : key(_key), val(_value), prev(_prev), next(_next) {}
};

//! @brief 
//! 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
//! 实现 LRUCache 类：
//! - LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
//! - int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1。
//! - void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value；
//!   如果不存在，则向缓存中插入该组 key-value。如果插入操作导致关键字数量超过
//!   capacity，则应该逐出最久未使用的关键字。
//! 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
//! 
//! @details 
//! 1 <= capacity <= 3000
//! 0 <= key <= 10000
//! 0 <= value <= 10^5
//! 最多调用 2 * 10^5 次 get 和 put
//! 
//! @example
//! input:  ["LRUCache", "put", "put", "get", "put", "get", "put", "get", 
//!          "get", "get"]
//!         [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//! output: [null, null, null, 1, null, -1, null, -1, 3, 4]
//! 
//! @note
//! 一开始是考虑使用单向链表，然后把最新访问的放在结尾，最先访问的放在头部。
//! 这样可以使得插入和删除都是 O(1) 完成，但是将中间结点提取到最新位置仍然无法解决。
//! 所以最后还是使用了双向链表来完成。
class LRUCache {
public:
  LRUCache(int capacity) {
    _capacity = capacity;
    _size = 0;

    _head = std::make_shared<DListNode>(-1, -1, nullptr);
    _tail = std::make_shared<DListNode>(-1, -1, _head, nullptr);
    _head->next = _tail;
  }
  
  int get(int key) {
    if (!_locator.count(key)) 
      return -1;

    auto p = _locator[key];
    moveToHead(p);

    return p->val;
  }
  
  void put(int key, int value) {
    // check if in list already
    if (_locator.count(key)) {
      update(key, value);
      return;
    }

    // insert new node in head
    insert(key, value);

    // remove least recently used node (tail)
    if (_size > _capacity) {
      removeTail();
    }
  }

private:
  int _size;
  int _capacity;
  std::shared_ptr<DListNode> _head; // most recently used
  std::shared_ptr<DListNode> _tail; // least recently used
  std::unordered_map<int, std::shared_ptr<DListNode>> _locator;

  void moveToHead(std::shared_ptr<DListNode> p) {
    if (p == _head->next)
      return;
    
    // disconnect from original position
    p->prev->next = p->next;
    p->next->prev = p->prev;
    // connect with _head->next
    _head->next->prev = p;
    p->next = _head->next;
    // connect with _head
    _head->next = p;
    p->prev = _head;
  }

  void removeTail() {
    auto p = _tail->prev;
    _locator.erase(p->key);
    // disconnect from original position
    p->prev->next = p->next;
    p->next->prev = p->prev;
    // clean p itself
    p->prev = nullptr;
    p->next = nullptr;
    
    _size -= 1;
  }

  void update(int key, int value) {
    auto p = _locator[key];
    p->val = value;
    moveToHead(p);
  }

  void insert(int key, int value) {
    auto newNode = std::make_shared<DListNode>(
      key, value, _head, _head->next);
    _head->next->prev = newNode;
    _head->next = newNode;

    _locator[key] = _head->next;
    _size += 1;
  }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  auto lRUCache = std::make_shared<LRUCache>(2);
  lRUCache->put(2, 1);
  lRUCache->put(1, 1);
  lRUCache->put(2, 3);
  lRUCache->put(4, 1); // remove (1, 1)
  std::cout << lRUCache->get(1) << std::endl;  // -1
  std::cout << lRUCache->get(2) << std::endl;  // 3
}
