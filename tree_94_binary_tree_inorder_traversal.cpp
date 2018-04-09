/*************************************************************************************** 
 *
 * 中序遍历二叉树。
 * 时间复杂度O(n)，空间复杂度O(n)。
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == NULL) {
            return result;
        }

        std::vector<int> left_vec = inorderTraversal(root->left);
        for (int i = 0; i < left_vec.size(); ++i) {
            result.push_back(left_vec[i]);
        }

        result.push_back(root->val);

        std::vector<int> right_vec = inorderTraversal(root->right);
        for (int i = 0; i < right_vec.size(); ++i) {
            result.push_back(right_vec[i]);
        }
        
        return result;
    }
};
