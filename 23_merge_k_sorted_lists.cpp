/*************************************************************************************** 
 *
 * 用21题合并两个有序列表的方法完成该题。
 * 时间复杂度O(n1+n2+n3+...)，空间复杂度O(1)。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        ListNode* head = NULL;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* node = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if (l1 != NULL) {
            node->next = l1;
        }
        if (l2 != NULL) {
            node->next = l2;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode* result = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            ListNode* list = lists[i];
            result = mergeTwoLists(result, list);
        }
        return result;
    }
};
