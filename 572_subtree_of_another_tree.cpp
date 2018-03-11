/*************************************************************************************** 
 *
 * 
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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) {
            return true;
        } else if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) {
            return false;
        } 
        if (a->val != b->val) {
            return false;
        }
        bool is_left_same = isSameTree(a->left, b->left);
        bool is_right_same = isSameTree(a->right, b->right);
        return is_left_same && is_right_same;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        if (isSameTree(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

