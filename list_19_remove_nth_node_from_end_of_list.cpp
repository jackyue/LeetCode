/*************************************************************************************** 
 *
 * front指针先走(n-1)步，prev指针再跟front指针一起走到链表末尾。最后删除prev指针。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return head;
        }
        ListNode *dump = new ListNode(-1);
        dump->next = head;
        ListNode *before = dump;
        ListNode *prev = head;
        ListNode *front = head;
        while (n > 1) {
            front = front->next;
            n--;
        }
        while (front->next != NULL) {
            before = before->next;
            prev = prev->next;
            front = front->next;
        }
        ListNode *next_node = prev->next;
        before->next = next_node;
        
        return dump->next;
    }
};
