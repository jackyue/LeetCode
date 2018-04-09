/*************************************************************************************** 
 *
 * 前序遍历。
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        int num = root->val;
        if (!root->left && !root->right && num == sum) {
            return true;
        }
        bool left = hasPathSum(root->left, sum - num);
        bool right = hasPathSum(root->right, sum - num);
        return left || right;
    }
};
