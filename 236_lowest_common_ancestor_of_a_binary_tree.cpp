/*************************************************************************************** 
 * 如果树节点为空，则返回空；
 * 如果树节点为p或者q节点则返回该节点；
 * 递归查找树节点的左子树，返回left；
 * 递归查找树节点的右子树，返回right；
 * 如果left和right都不为空，则说明该节点为最小公共节点；
 * 如果left不为空，则说明left为最小公共节点；
 * 如果right不为空，则说明right为最小公共节点。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        }
        if (left != NULL) {
            return left;
        } else {
            return right;
        }
    }
};
