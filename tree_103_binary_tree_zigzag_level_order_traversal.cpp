/*************************************************************************************** 
 *
 * 分层遍历二叉树，需要判断层级level的奇数偶数。
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
    void inorderTraversal(TreeNode *node, int level, std::vector<std::vector<int> > *result) {
        if (node == NULL) {
            return;
        }
        bool is_need_reverse = (level + 1) % 2 == 0 ? true : false;
        if (result->size() < level + 1) {
            std::vector<int> node_vec;
            node_vec.push_back(node->val);
            result->push_back(node_vec);
        } else {
            std::vector<int> &node_vec = (*result)[level];
            if (is_need_reverse) {
                std::reverse(node_vec.begin(), node_vec.end());
            }
            node_vec.push_back(node->val);
            if (is_need_reverse) {
                std::reverse(node_vec.begin(), node_vec.end());
            }
        }
        inorderTraversal(node->left, level + 1, result);
        inorderTraversal(node->right, level + 1, result);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int> > result;
        int level = 0;
        inorderTraversal(root, level, &result);
        return result;
    }
};
