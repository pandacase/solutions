#include <string>
#include <vector>
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! @brief 
//! 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 
//! 
//! @details 
//! 链表中节点的数目在范围 [0, 5 * 104] 内
//! -105 <= Node.val <= 105
//! 
//! @example
//! input:  head = [4,2,1,3]
//! output: [1,2,3,4]
//!
//! @note
//! 1. 自顶向下归并
//! 时间复杂度 O(nlogn)，空间复杂度 O(logn)（栈递归空间）
//! 
//! 2. 自底向上归并
//! 时间复杂度 O(nlogn)，空间复杂度 O(1)（无需递归）
class Solution {
public:
  ListNode* 
  sortList(ListNode* head) 
  {
    return sortList(head, nullptr);
  }

private:
  const int MAX_VAL = 1e5 + 1;

  ListNode*
  merge(ListNode* l1, ListNode* l2)
  {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while (l1 != nullptr || l2 != nullptr) {
      int val1 = l1 != nullptr ? l1->val : MAX_VAL;
      int val2 = l2 != nullptr ? l2->val : MAX_VAL;

      if (val1 <= val2) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }

      curr = curr->next;
    }
    return dummy->next;
  }

  ListNode* 
  sortList(ListNode* begin, ListNode* end) 
  {
    if (!begin) // length = 0
      return nullptr;
    if (begin->next == end) { // length = 1
      begin->next = nullptr;
      return begin;
    }

    ListNode *slow = begin, *fast = begin;
    while (fast != end) {
      slow = slow->next;
      fast = fast->next;
      if (fast != end) {
        fast = fast->next;
      }
    }
    ListNode* mid = slow;

    return merge(sortList(begin, mid), sortList(mid, end));
  }
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(2, new ListNode(1, new ListNode(3)));

  auto head = sol.sortList(l1);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
