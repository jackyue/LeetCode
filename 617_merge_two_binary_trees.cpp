/*************************************************************************************** 
 *
 * 如果t1,t2都为空，则返回空；如果t1为空t2不为空，则返回t2；如果t1不为空t2为空，则返回t1。
 * t1,t2节点value求和，加和放到创建的新节点里。
 * 递归合并t1的左节点和t2的左节点，递归合并t1的右节点和t2的右节点。
 * 返回创建的新节点。
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } else if (t1 == NULL && t2 != NULL) {
            return t2;
        } else if (t1 != NULL && t2 == NULL) {
            return t1;
        }
        int val = t1->val + t2->val;
        TreeNode *node = new TreeNode(val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};
