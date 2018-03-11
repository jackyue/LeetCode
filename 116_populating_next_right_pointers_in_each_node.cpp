/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connectNode(std::vector<TreeLinkNode*> node_vec) {
        if (node_vec.empty()) {
            return;
        }
        std::vector<TreeLinkNode*> node_vec_new;
        for (uint32_t i = 0; i < node_vec.size(); ++i) {
            TreeLinkNode* node = node_vec[i];
            if (node->left != NULL && node->right != NULL) {
                node_vec_new.push_back(node->left);
                node_vec_new.push_back(node->right);
            }
            if (i != node_vec.size() - 1) {
                node->next = node_vec[i + 1];
            }
            else {
                node->next = NULL;
            }
        }
        connectNode(node_vec_new);
    }
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        std::vector<TreeLinkNode*> node_vec;
        node_vec.push_back(root);
        connectNode(node_vec);
    }
};
