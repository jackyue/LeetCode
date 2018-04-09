/*************************************************************************************** 
 *
 * priority_queue默认是最大堆，该问题需要实现最小堆。
 * operator < 默认只有一个参数，如果需要两个参数则需要设置友元函数
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

struct Node {
    int m_num;
    Node(int num) {
        m_num = num;
    }
    friend bool operator < (const Node &a, const Node &b);
};

inline bool operator < (const Node &a, const Node &b) {
    return a.m_num < b.m_num;
}

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        std::priority_queue<Node> queue;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                Node node(matrix[i][j]);
                queue.push(node);
                if (queue.size() > k) {
                    queue.pop();
                }
            }
        }
        return queue.top().m_num;
    }
};

