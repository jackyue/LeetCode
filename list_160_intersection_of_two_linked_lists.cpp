/*************************************************************************************** 
 *
 * 首先保存第一个链表的所有节点到一个set中，查找第二个链表中第一个在set集合中出现的节点。
 * 时间复杂度O(m+n)，空间复杂度O(1)
 * 其他解法: 先遍历两个链表，计算链表长度差值k。
 *          第二次遍历时，较长链表首先走k步，然后依次比较两个链表的节点。
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
