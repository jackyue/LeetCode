/*************************************************************************************** 
 *
 * 用prev节点记录需要交换的两个节点的前一个节点，交换之前判断两个节点是否都为非空。
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* dump = new ListNode(-1);
        ListNode* prev = dump;
        dump->next = head;
        ListNode* current = head;
        while (current != NULL && current->next != NULL) {
            prev->next = current->next;
            ListNode* front = current->next->next;
            current->next->next = current;
            current->next = front;
            prev = current;
            current = front;
        }
        return dump->next;
    }
};
