/*************************************************************************************** 
 *
 * 新增一个list保存原始list逆转之后的结果，然后对比两个list，是否每个node值都相同。
 * 时间复杂度O(n)，空间复杂度O(n)。
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        std::list<int> list;
        list.push_back(head->val);
        ListNode* node = head->next;
        while (node != NULL) {
            list.push_back(node->val);
            node = node->next;
        }
        std::list<int>::reverse_iterator rit = list.rbegin();
        std::list<int>::iterator it = list.begin();
        for (; rit != list.rend() && it != list.end(); ++rit, ++it) {
            if (*it != *rit) {
                return false;
            }
        }
        return true;
    }
};
