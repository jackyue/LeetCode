/*************************************************************************************** 
 *
 * 比较左右树：
 * 如果两棵树都为NULL，则返回true。
 * 如果其中一颗树为NULL，则返回false。
 * 如果两棵树的根节点数值相同，则递归判断左树的左子树和右树的右子树是否是镜像，
 * 右树的左子树和左树的右子树是否是镜像。
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
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        } else {
            return isSymmetric(left->left, right->right) &&
                   isSymmetric(left->right, right->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
};
