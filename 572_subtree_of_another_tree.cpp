/*************************************************************************************** 
 *
 * 如果s为空，返回false。
 * 首先判断s和t两个树是否相同。
 * 递归判断s的左子树是否包含t，递归判断s的右子树是否包含t。
 * 如果某个子树返回true，则结果返回true。
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

