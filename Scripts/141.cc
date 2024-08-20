#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//! @brief 
//! 给你一个链表的头节点 head ，判断链表中是否有环。
//! 
//! @details 
//! 链表中节点的数目范围是 [0, 10^4]
//! -10^5 <= Node.val <= 10^5
//! pos 为 -1 或者链表中的一个有效索引 。
//! 
//! @note
//! 1. 必须先单独检查特例之后才能创建快指针，否则会尝试访问 head
//! 2. 在循环中也必须同时检查当前 pp 与 pp->next，同理。
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head || !(head->next)) return false;
    ListNode *p = head, *pp = head->next;
    while (p != pp) {
      if (!pp || !(pp->next))
        return false;
      p = p->next;
      pp = pp->next->next;
    }
    return true;
  }
};


int main() {
  Solution sol;

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = head;

  auto ans = sol.hasCycle(head);

  //! 0  
  std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
