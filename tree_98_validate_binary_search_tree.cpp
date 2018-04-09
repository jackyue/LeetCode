/*************************************************************************************** 
 *
 * 中序遍历二叉树，若前一节点小于下一节点一直成立，则说明是搜索二叉树，否则不是。
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
    bool inorderTravelsal(TreeNode* root, long* prev_val) {
        if (root == NULL) {
            return true;
        }

        bool left = inorderTravelsal(root->left, prev_val);
        if (root->val <= *prev_val) {
            return false;
        }
        *prev_val = root->val;
        bool right = inorderTravelsal(root->right, prev_val);
        if (left && right) {
            return true;
        } else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long prev_val = LONG_MIN;
        return inorderTravelsal(root, &prev_val);
    }
};
