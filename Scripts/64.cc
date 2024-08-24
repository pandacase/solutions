#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! @brief 
//! 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//! 
//! @details 
//! 链表中节点的数目在范围 [0, 500] 内
//! -100 <= Node.val <= 100
//! 0 <= k <= 2 * 10^9
//! 
//! @note
//! 
class Solution {
public:
  ListNode* 
  rotateRight(ListNode* head, int k) 
  {
    if (!head) return head;
    
    int size = 0;
    for (auto p = head; p != nullptr; p = p->next) {
      size += 1;
      if (p->next == nullptr) {
        p->next = head;
        break;
      }
    }

    int offset = size - (k % size) - 1;
    std::cout << offset << std::endl;
    while (offset--)
      head = head->next;
    auto p = head;
    head = head->next;
    p->next = nullptr;

    return head;
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

  auto head = sol.rotateRight(l1, 0);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
