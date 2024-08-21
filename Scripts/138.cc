#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val, Node* _next = NULL, Node* _rand = NULL) {
    val = _val;
    next = _next;
    random = _rand;
  }
};

//! @brief 
//! 给你一个长度为n的链表，每个节点包含一个额外增加的随机指针random，
//! 该指针可以指向链表中的任何节点或空节点。
//! 
//! 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，
//! 其中每个新节点的值都设为其对应的原节点的值。
//! 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
//! 并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//! 复制链表中的指针都不应指向原链表中的节点。
//! 
//! 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y。
//! 那么在复制链表中对应的两个节点 x 和 y，同样有 x.random --> y。
//! 返回复制链表的头节点。
//!
//! 用一个由 n 个节点组成的链表来表示输入/输出中的链表。
//! 每个节点用一个 [val, random_index] 表示：
//! - val：一个表示 Node.val 的整数。
//! - random_index：随机指针指向的节点索引（范围从 0 到 n-1）；
//!   如果不指向任何节点，则为 null 。
//! 
//! @details 
//! 0 <= n <= 1000
//! -10^4 <= Node.val <= 10^4
//! Node.random 为 null 或指向链表中的节点。
//! 
//! @example
//! input:  head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//! output:        [[7,null],[13,0],[11,4],[10,2],[1,0]]
//! 
//! input:  head = [[1,1],[2,1]]
//! output:        [[1,1],[2,1]]
//!
//! input:  head = [[3,null],[3,0],[3,null]]
//! output:        [[3,null],[3,0],[3,null]]
//! 
//! @note
//! 1. 仍然使用哈希表的回溯方法：
//! 递归调用自己，头递归的时候填充哈希表并设置 next。
//! 尾递归的时候设置 random。
//! 
//! 2. 不使用哈希表的方法：
//! 将哈希表的结点对应关系融入到链表中去。
//! 假设原来的链表是 A -> B -> C -> null
//! - 遍历第一次：
//! 复制一遍 val 后构造成为
//! A -> newA -> B -> newB -> C -> newC -> null
//! - 遍历第二次：
//! 现在显然这个链表本身已经具有了哈希对应关系，即 A->next = newA
//! 所以这一次遍历就可以给所有 new 结点设置 random
//! - 遍历第三次：
//! 每间隔一个结点串起所有 new 结点即得到了新的链表。
class Solution {
public:
  Node* 
  copyRandomList(Node* head) 
  {
    std::unordered_map<Node*, Node*> locator;
    Node *dummy = new Node(0), *curr = dummy;
    
    int index = 0;
    for (auto p = head; p != nullptr; p = p->next) {
      curr->next = new Node(p->val);
      locator[p] = curr->next;

      curr = curr->next;
      index += 1;
    }

    curr = dummy->next;
    for (auto p = head; p != nullptr; p = p->next) {
      if (p->random != nullptr)
        curr->random = locator[p->random];
      else 
        curr->random = nullptr;

      curr = curr->next;
    }
    
    return dummy->next;
  }
};


int main() {
  Solution sol;

  Node* n5 = new Node(1,  nullptr);
  Node* n4 = new Node(10, n5);
  Node* n3 = new Node(11, n4);
  Node* n2 = new Node(13, n3);
  Node* n1 = new Node(7,  n2);

  n1->random = nullptr;
  n2->random = n1;
  n3->random = n5;
  n4->random = n3;
  n5->random = n1;

  auto head = sol.copyRandomList(n1);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
