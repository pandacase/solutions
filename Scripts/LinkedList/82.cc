#include <string>
#include <vector>
#include <iostream>

#define MAX_VAL 100

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! @brief 
//! 给定一个已排序的链表的头head，删除原始链表中所有重复数字的节点，
//! 只留下不同的数字 。返回 已排序的链表。 
//! 
//! @details 
//! 链表中节点数目在范围 [0, 300] 内
//! -100 <= Node.val <= 100
//! 题目数据保证链表已经按升序 排列
//! 
//! @example
//! input:  head = [1,2,3,3,4,4,5]
//! output: [1,2,5]
//! 注意，只要出现重复了是全都删掉该值的结点，一个不留
//!
//! @note
//! while 的条件也可以是 &&，最后直接将 curr->next 
//! 指向未遍历完的链表的当前位置即可续上了
class Solution {
public:
  ListNode* 
  deleteDuplicates(ListNode* head) 
  {
    ListNode* dummy = new ListNode(MAX_VAL + 1, head);
    auto prev = dummy;
    auto curr = dummy->next;
    while (curr && curr->next) {
      auto next = curr->next;
      if (!next) break;
      int value = MAX_VAL + 1;
      if (curr->val == next->val) {
        value = curr->val;
        auto p = prev;
        while (prev->next && prev->next->val == value)
          prev->next = prev->next->next;
        curr = prev->next;
      } else {
        prev = prev->next;
        curr = prev->next;
      }
    }
    return dummy->next;
  }
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(2)));

  auto head = sol.deleteDuplicates(l1);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
