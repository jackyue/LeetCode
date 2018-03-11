/*************************************************************************************** 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        std::set<ListNode*> node_set;
        ListNode* node = headA;
        while (node != NULL) {
            node_set.insert(node);
            node = node->next;
        }
        node = headB;
        while (node != NULL) {
            if (node_set.find(node) != node_set.end()) {
                return node;
            }
            node = node->next;
        }
        return NULL;
    }
};
