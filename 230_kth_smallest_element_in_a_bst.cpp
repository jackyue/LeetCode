/*************************************************************************************** 
 * 
 * 用c++的优先队列实现，需要重载小于号操作符，将最小堆改为最大堆。
 * 时间复杂度O(n)，空间复杂度O(k)。
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
struct Node {
    int m_value;
    Node(int value) {
        m_value = value;
    }
    friend bool operator < (const Node& a, const Node& b);
};

inline bool operator < (const Node& a, const Node& b) {
    return a.m_value < b.m_value;
}

class Solution {
public:
    void insertTreeNode(const TreeNode* root,
            std::priority_queue<Node>& queue, const int k) {
        if (root == NULL) {
            return;
        }
        Node node(root->val);
        queue.push(node);
        if (queue.size() > k) {
            queue.pop();
        }
        insertTreeNode(root->left, queue, k);
        insertTreeNode(root->right, queue, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        std::priority_queue<Node> queue;
        insertTreeNode(root, queue, k);
        return queue.top().m_value;
    }
};
