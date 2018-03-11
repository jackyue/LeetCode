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
    void TraverseTree(TreeNode* node, std::vector<int> &sums, int& count, const int sum) {
        if (node == NULL) {
            return;
        }

        for (uint32_t i = 0; i < sums.size(); ++i) {
            int add_node = sums[i] + node->val;
            if (add_node == sum) {
                ++count;
            }
            sums[i] = add_node;
        }
        if (node->val == sum) {
            ++count;
        }
        sums.push_back(node->val);
        std::vector<int> left_sums = sums;
        std::vector<int> right_sums = sums;
        TraverseTree(node->left, left_sums, count, sum);
        TraverseTree(node->right, right_sums, count, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        int count = 0;
        std::vector<int> sums;
        TraverseTree(root, sums, count, sum);
        return count;
    }
};
