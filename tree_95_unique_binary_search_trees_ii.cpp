/*************************************************************************************** 
 *
 * 遍历1到n，分别用i作为根节点，以1~i-1为节点建树，以i+1~n为节点建树，递归调用建树方法。
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
    std::vector<TreeNode*> makeBST(const int begin, const int end) {
        std::vector<TreeNode*> result;
        if (begin > end) {
            result.push_back(NULL);
            return result;
        }
        for (int i = begin; i <= end; ++i) {
            std::vector<TreeNode*> left_vec = makeBST(begin, i-1);
            std::vector<TreeNode*> right_vec = makeBST(i+1, end);
            for (int j = 0; j < left_vec.size(); ++j) {
                for (int k = 0; k < right_vec.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    TreeNode* left = left_vec[j];
                    TreeNode* right = right_vec[k];
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> result;
        if (n == 0) {
            return result;
        }
        return makeBST(1, n);
    }
};
