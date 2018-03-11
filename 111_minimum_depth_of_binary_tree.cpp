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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_depth = minDepth(root->left) + 1;
        int right_depth = minDepth(root->right) + 1;
        if (!root->left) {
            return right_depth;
        }
        if (!root->right) {
            return left_depth;
        }
        return left_depth < right_depth ? left_depth : right_depth;
    }
};