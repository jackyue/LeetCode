/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if (head == NULL) {
        return NULL;
      }
      ListNode* odd_node = head;
      ListNode* even_node = head->next;
      ListNode* odd_head = odd_node;
      ListNode* even_head = even_node;
      while (even_node && even_node->next) {
        odd_node->next = even_node->next;
        odd_node = odd_node->next;
        even_node->next = even_node->next->next;
        even_node = even_node->next;
      }
      odd_node->next = even_head;
      return odd_head;
    }
};
