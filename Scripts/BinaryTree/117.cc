#include <string>
#include <vector>
#include <iostream>
#include <queue>


class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node()
   : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val)
   : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

//! @brief 
//! 给定一个二叉树：
//! struct Node {
//!   int val;
//!   Node *left;
//!   Node *right;
//!   Node *next;
//! }
//! 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
//! 如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
//! 初始状态下，所有 next 指针都被设置为 NULL 。
//! 
//! @details 
//! 树中的节点数在范围 [0, 6000] 内
//! -100 <= Node.val <= 100
//! 
//! 
//! @example 
//! input:  root = [1,2,3,4,5,null,7]
//! output: [1,#,2,3,#,4,5,7,#]
//! ![](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)
//! 给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个
//! 右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），
//! '#' 表示每层的末尾。
//! 
//! input:  root = []
//! output: []
//! 
//! @note
//! 可以使用队列进行层序遍历。（可通过）
//!
//! 进阶：你只能使用常量级额外空间(不算递归的空间)
//! 实际上当一层链接完毕后，可以遍历这一层的链表得到下一层，就不需要队列了
//! (这部分是copy的，原来写的TLE了，等待重写中...)
class Solution {
public:
  void 
  handle(Node* &prevNode, Node* &p, Node* &nextHead) 
  {
    if (prevNode) {
      prevNode->next = p;
    } 
    if (!nextHead) {
      nextHead = p;
    }
    prevNode = p;
  }

  Node* 
  connect(Node* root) 
  {
    if (!root) return nullptr;
    
    Node* head = root;
    while (head) {
      Node* prevNode = nullptr, *nextHead = nullptr;
      for (auto p = head; p != nullptr; p = p->next) {
        if (p->left) 
          handle(prevNode, p->left, nextHead);
        if (p->right) 
          handle(prevNode, p->right, nextHead);
      }
      head = nextHead;
    }
    return root;
  }

  Node* 
  connectWithQueue(Node* root) 
  {
    queue.push(root);
    queue.push(nullptr);

    while (!queue.empty()) {
      if (queue.front() != nullptr) {
        auto curr = queue.front();
        queue.pop();
        if (curr->left)
          queue.push(curr->left);
        if (curr->right)
          queue.push(curr->right);
        curr->next = queue.front();

        if (curr->next == nullptr)
          queue.push(nullptr);
      } else {
        queue.pop();
      }
    }
    
    return root;
  }

private:
  std::queue<Node*> queue;
};


int main() {
  Solution sol;
  auto root =     new Node(1, 
            nullptr,     new Node(-9,
                    nullptr,      new Node(8, 
                            new Node(4), new Node(-3)
    , nullptr), nullptr), nullptr);
  auto ans = sol.connect(root);

  // // print link
  std::cout << ans << std::endl;
}
