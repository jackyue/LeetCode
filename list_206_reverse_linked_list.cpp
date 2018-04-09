/*************************************************************************************** 
 *
 * node1->node2->node3->node4
 * pre_node指向上一个节点，next_node保存下一个节点，head指向当前节点。
 * 时间复杂度O(logn)，空间复杂度O(1)。
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* pre_node = NULL;
        ListNode* next_node = NULL;
        while (head != NULL) {
            next_node = head->next;
            head->next = pre_node;
            pre_node = head;
            head = next_node;
        }
        return pre_node;
    }
};
