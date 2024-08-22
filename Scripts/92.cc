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
//! 给你单链表的头指针 head 和两个整数 left 和 right ，
//! 其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，
//! 返回反转后的链表 。(结点的序号从 1 算起)
//! 
//! @details 
//! 链表中节点数目为 n
//! 1 <= n <= 500
//! -500 <= Node.val <= 500
//! 1 <= left <= right <= n
//! 
//! @example
//! input:  head = [1,2,3,4,5], left = 2, right = 4
//! output: [1,4,3,2,5]
//! 
//! input:  head = [5], left = 1, right = 1
//! output: [5]
//! 
//! @note
//! 链表的各种灵活操作都建立在使用许多辅助变量记录关键的结点！
//! 
//! 方法二是将遍历到的每一个区间内的结点提到 prev 之后
//! 
class Solution {
private:
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

public:
  ListNode* 
  reverseBetween(ListNode* head, int left, int right) 
  {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    int index = 0;
    ListNode *prev = nullptr, *succ = nullptr;
    ListNode *leftPtr = nullptr, *rightPtr = nullptr;
    for (auto p = dummy; p != nullptr; p = p->next) {
      if (index == left - 1) {
        prev = p;
        leftPtr = p->next;
      }
      if (index == right) {
        rightPtr = p;
        succ = p->next;
        break;
      }
      index += 1;
    }

    rightPtr->next = nullptr;
    prev->next = reverseList(leftPtr);
    leftPtr->next = succ;

    return dummy->next;
  }

  ListNode* 
  reverseBetween2(ListNode* head, int left, int right) 
  {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    int index = 0;
    ListNode *prev, *leftPtr, *succ;
    ListNode *p = dummy;
    while (p != nullptr) {
      if (index == left - 1) {
        prev = p;
        leftPtr = p->next;
      }
      ListNode* next = p->next;
      if (left <= index && index <= right) {
        if (index == right)
          succ = p->next;
        p->next = prev->next;
        prev->next = p;
      }
      p = next;
      index += 1;
    }

    leftPtr->next = succ;

    return dummy->next;
  }
};


int main() {
  Solution sol;

  // ListNode* l1 = new ListNode(
  //                 1, new ListNode(
  //                   2, new ListNode(
  //                     3, new ListNode(
  //                       4, new ListNode(5)))));
  ListNode* l2 = new ListNode(5);

  auto head = sol.reverseBetween2(l2, 1, 1);

  // print link
  for (auto p = head; p != nullptr; p = p->next) {
    std::cout << p->val << " ";
  }
  std::cout << std::endl;
}
