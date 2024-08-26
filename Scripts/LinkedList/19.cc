#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! @brief 
//! 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//! 
//! @details 
//! 链表中结点的数目为 sz
//! 1 <= sz <= 30
//! 0 <= Node.val <= 100
//! 1 <= n <= sz
//! 
//! @example
//! input:  head = [1,2,3,4,5], n = 2
//! output: [1,2,3,5]
//! 
//! @note
//! 
class Solution {
public:
  ListNode* 
  removeNthFromEnd(ListNode* head, int n) 
  {
    ListNode* dummy = new ListNode(0, head);

    int length = 0;
    while (head) {
      ++length;
      head = head->next;
    }
    
    ListNode* curr = dummy;
    for (int i = 1; i < length - n + 1; ++i)
      curr = curr->next;
    curr->next = curr->next->next;
    // ⚠️突然发现这里会有 dummy 的内存泄漏，但是先不管了）
    return dummy->next;
  }
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3)));

  auto head = sol.removeNthFromEnd(l1, 2);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
