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
//! 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，
//! 使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//! 你应当 保留 两个分区中每个节点的初始相对位置。
//! 
//! @details 
//! 链表中节点的数目在范围 [0, 200] 内
//! -100 <= Node.val <= 100
//! -200 <= x <= 200
//! 
//! @example 
//! input:  head = [1,4,3,2,5,2], x = 3
//! output: [1,2,2,4,3,5]
//! 
//! input:  head = [2,1], x = 2
//! output: [1,2]
//! 
//! @note
//! 
class Solution {
public:
  ListNode* 
  partition(ListNode* head, int x) 
  {
    if (!head) return head;

    ListNode* dummy = new ListNode(0, head);
    ListNode* curr = dummy;
    while (curr && curr->next) {
      if ((curr->next)->val >= x)
        break;
      curr = curr->next;
    }
    // now curr is at the last continuous < x node
    auto bound = curr;
    if (!bound) return head;

    while (curr && curr->next) {
      if ((curr->next)->val < x) {
        auto p = curr->next;
        curr->next = curr->next->next;
        p->next = bound->next;
        bound->next = p;
        bound = bound->next;
      } else {
        curr = curr->next;
      }
    }

    return dummy->next;
  }
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(
                  1, new ListNode(
                    4, new ListNode(
                      3, new ListNode(
                        2, new ListNode(
                          5, new ListNode(
                            2
                          ))))));

  auto head = sol.partition(l1, 3);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
