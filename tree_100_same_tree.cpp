/*************************************************************************************** 
 *
 * 递归判断左子树是否相同，递归判断右子树是否相同。
 * 判断当前节点是否相同。
 * 如果以上条件都成立，则说明两棵树相同。
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
