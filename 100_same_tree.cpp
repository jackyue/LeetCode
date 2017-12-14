/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        bool is_left_same = isSameTree(p->left, q->left);
        bool is_right_same = isSameTree(p->right, q->right);
        if (is_left_same && is_right_same && (p->val == q->val)) {
            return true;
        } else {
            return false;
        }
    }
};
