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
//! 将两个升序链表合并为一个新的 升序 链表并返回。
//! 新链表是通过拼接给定的两个链表的所有节点组成的。 
//! 
//! @details 
//! 两个链表的节点数目范围是 [0, 50]
//! -100 <= Node.val <= 100
//! l1 和 l2 均按非递减顺序排列
//! 
//! @example
//! input:  l1 = [1,2,4], l2 = [1,3,4]
//! output: [1,1,2,3,4,4]
//! 
//! input:  l1 = [], l2 = [0]
//! output: [0]
//! 
//! @note
//! while 的条件也可以是 &&，最后直接将 curr->next 
//! 指向未遍历完的链表的当前位置即可续上了
class Solution {
public:
  ListNode* 
  mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while (l1 != nullptr || l2 != nullptr) {
      int val1 = l1 != nullptr ? l1->val : MAX_VALUE;
      int val2 = l2 != nullptr ? l2->val : MAX_VALUE;
      
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
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  auto head = sol.mergeTwoLists(l1, l2);

  // print link
  for (auto p = head; p != NULL; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
