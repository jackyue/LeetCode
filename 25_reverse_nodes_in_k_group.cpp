/*************************************************************************************** 
 *
 * 用prev节点记录需要逆序的k个节点的前一个节点，current节点记录需要逆序的k个节点的第一个
 * 节点，end节点记录需要逆序的k个节点的最后一个节点。current至end节点逆序即可。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        ListNode* dump = new ListNode(-1);
        dump->next = head;
        ListNode* prev = dump;
        ListNode* current = head;
        ListNode* end = head;
        int num = 0;
        while (end != NULL) {
            num++;
            if (num == k) {
                ListNode* front = end->next;
                
                ListNode* p = current;
                ListNode* q = p->next;
                while (q != front) {
                    ListNode* next = q->next;
                    q->next = p;
                    p = q;
                    q = next;
                }

                prev->next = end;
                prev = current;
                current->next = front;
                end = current;
                current = front;
                num = 0;
            }
            end = end->next;
        }
        return dump->next;
    }
};
