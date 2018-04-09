/*************************************************************************************** 
 *
 * 后序遍历，用一个sum值跟踪记录求和值。
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
    void SumTreeNode(TreeNode* node, int& sum) {
        if (node == NULL) {
            return;
        }
        SumTreeNode(node->right, sum);
        int tmp = node->val;
        node->val = node->val + sum;
        sum = sum + tmp;
        SumTreeNode(node->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        int sum = 0;
        SumTreeNode(root, sum);
        return root;
    }
};
