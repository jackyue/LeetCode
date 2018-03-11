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
    int DepthTree(TreeNode* root, int& max_path) {
        if (root == NULL) {
            return -1;
        }
        int left_depth = DepthTree(root->left, max_path) + 1;
        int right_depth = DepthTree(root->right, max_path) + 1; 
        if (left_depth + right_depth > max_path) {
            max_path = left_depth + right_depth;
        }
        if (left_depth > right_depth) {
            return left_depth;
        } else {
            return right_depth;
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int max_path = 0;
        DepthTree(root, max_path);
        return max_path;
    }
};
