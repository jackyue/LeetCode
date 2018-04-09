/*************************************************************************************** 
 *
 * 前序遍历数组的第一个值为根节点的值；
 * 中序遍历数组中该值的左边的值作为左子树的中序遍历结果；
 * 中序遍历数组中该值的右边的值作为右子树的中序遍历结果；
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.empty()) {
            return NULL;
        }
        int num = preorder[0];
        TreeNode* node = new TreeNode(num);
        std::vector<int> left_inorder;
        std::vector<int> right_inorder;
        bool find_root = false;

        std::vector<int> left_preorder;
        std::vector<int> right_preorder;
        int index = 1;
        for (int i = 0; i < inorder.size(); ++i) {
            if (num == inorder[i]) {
                find_root = true;
                continue;
            }
            if (!find_root) {
                left_preorder.push_back(preorder[index]);
                left_inorder.push_back(inorder[i]);
            } else {
                right_preorder.push_back(preorder[index]);
                right_inorder.push_back(inorder[i]);
            }
            ++index;
        }
        TreeNode* left_node = buildTree(left_preorder, left_inorder);
        TreeNode* right_node = buildTree(right_preorder, right_inorder);
        node->left = left_node;
        node->right = right_node;
        return node;
    }
};
