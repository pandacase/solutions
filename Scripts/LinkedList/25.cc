
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//! @brief 
//! 给你链表的头节点 head，每 k 个节点一组进行翻转，
//! 请你返回修改后的链表。
//! 
//! k 是一个正整数，它的值小于或等于链表的长度。
//! 如果节点总数不是 k 的整数倍，
//! 那么请将最后剩余的节点保持原有顺序。
//! 
//! 你不能只是单纯的改变节点内部的值，
//! 而是需要实际进行节点交换。
//! 
//! @details 
//! 链表中的节点数目为 n。
//! 1 <= k <= n <= 5000
//! 0 <= Node.val <= 1000
//! 
//! @example 
//! input: head = [1,2,3,4,5], k = 2
//! output: [2,1,4,3,5]
//! 
//! input: head = [1,2,3,4,5], k = 3
//! output: [3,2,1,4,5]
//! 
class Solution {
public:
  ListNode* 
  reverseKGroup(ListNode* head, int k) 
  {
    if (!head || k == 1)
      return head;
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy, *succ = nullptr;
    ListNode *left, *right ;

    while (head) {
      size_t i = 0;
      for (; i < k && head; ++i) {
        if (i == 0) {
          left = head;
        }
        if (i == k - 1) {
          right = head;
          succ = right->next;
        }
        head = head->next;
      }
      if (i != k) break;

      // reverse
      right->next = nullptr;
      prev->next = reverseList(left);
      left->next = succ; // left is now on right side
      prev = left;
    }
    
    auto ans = dummy->next;
    delete dummy;
    return ans;
  }

private:

  ListNode*
  reverseList(ListNode* head)
  {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};