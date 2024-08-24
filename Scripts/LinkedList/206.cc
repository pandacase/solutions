#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#define MAX_VALUE 101

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! @brief 
//! 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//! 
//! @details 
//! 链表中节点的数目范围是 [0, 5000]
//! -5000 <= Node.val <= 5000
//! 
//! @note
//! 
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(
                  1, new ListNode(
                    2, new ListNode(
                      3, new ListNode(
                        4, new ListNode(
                          5)))));

  auto head = sol.reverseList(l1);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
