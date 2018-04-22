/*************************************************************************************** 
 *
 * 
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
    void PreorderTraversal(TreeNode *node, int level,
            std::vector<std::vector<int> > *result) {
        if (node == NULL) {
            return;
        }
        if (result->size() < (level + 1)) {
            std::vector<int> level_vec;
            level_vec.push_back(node->val);
            result->push_back(level_vec);
        } else {
            std::vector<int> &level_vec = (*result)[level];
            level_vec.push_back(node->val);
        }
        PreorderTraversal(node->left, level + 1, result);
        PreorderTraversal(node->right, level + 1, result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        std::vector<std::vector<int> > result;
        PreorderTraversal(root, level, &result);
        return result;
    }
};
