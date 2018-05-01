/*************************************************************************************** 
 *
 * 如果传入的节点为空或者链表最后一个元素则返回；传入节点指向下个节点。
 * 时间复杂度O(n)，空间复杂度O(1)
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
    void deleteNode(ListNode* node) {
        if (!node || !node->next) {
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
