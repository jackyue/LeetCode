/*************************************************************************************** 
 *
 * 时间复杂度O(N)，空间复杂度O(1)。
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* left_node = invertTree(root->right);
        TreeNode* right_node = invertTree(root->left);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};
