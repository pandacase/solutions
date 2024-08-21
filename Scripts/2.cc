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
//! 给你两个 非空 的链表，表示两个非负的整数。
//! 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储一位数字。
//! 请你将两个数相加，并以相同形式返回一个表示和的链表。
//! 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//! 
//! @details 
//! 每个链表中的节点数在范围 [1, 100] 内
//! 0 <= Node.val <= 9
//! 题目数据保证列表表示的数字不含前导零
//! 
//! @example
//! input:  l1 = [2,4,3], l2 = [5,6,4]
//! output: [7,0,8]
//! 342 + 465 = 807.
//! 
//! input:  l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//! output: [8,9,9,9,0,0,0,1]
//! 
//! @note
//! 
class Solution {
public:
  std::pair<int, int> 
  oneBitAdder(int a, int b, int carry) {
    int res = a + b + carry;
    return {/*result*/res % 10, /*carry*/res / 10};
  }

  ListNode* 
  addTwoNumbers(ListNode* l1, ListNode* l2) 
  {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      // proxy val
      int val1 = (l1 != nullptr) ? l1->val : 0;
      int val2 = (l2 != nullptr) ? l2->val : 0;
      // compute
      auto [res, newCarry] = oneBitAdder(val1, val2, carry);
      curr->next = new ListNode(res);
      carry = newCarry;
      // update iterator
      curr = curr->next;
      if (l1 != nullptr) l1 = l1->next;
      if (l2 != nullptr) l2 = l2->next;
    }

    return dummy->next;
  }

  // ListNode* 
  // addTwoNumbers(ListNode* l1, ListNode* l2) 
  // {
  //   int carry = 0;
  //   auto p1 = l1, p2 = l2, lastp1 = l1;
  //   while (p1 != nullptr && p2 != nullptr) {
  //     auto [res, newCarry] = oneBitAdder(p1->val, p2->val, carry);
  //     p1->val = res;
  //     carry = newCarry;

  //     lastp1 = p1;
  //     p1 = p1->next;
  //     p2 = p2->next;
  //   }

  //   while (p1 != nullptr) {
  //     auto [res, newCarry] = oneBitAdder(p1->val, 0, carry);
  //     lastp1->next = new ListNode(res);
  //     carry = newCarry;
  //     lastp1 = lastp1->next;

  //     p1 = p1->next;
  //   }

  //   while (p2 != nullptr) {
  //     auto [res, newCarry] = oneBitAdder(0, p2->val, carry);
  //     lastp1->next = new ListNode(res);
  //     carry = newCarry;
  //     lastp1 = lastp1->next;

  //     p2 = p2->next;
  //   }

  //   if (carry) {
  //     lastp1->next = new ListNode(carry);
  //   }

  //   return l1;
  // }
};


int main() {
  Solution sol;

  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  auto head = sol.addTwoNumbers(l1, l2);

  // print link
  for (auto p = head; head != NULL; head = head->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
