/*************************************************************************************** 
 *
 * 
 *
 ***************************************************************************************/


class Solution {
public:
    int dns(std::vector<std::vector<int> >& M, std::vector<int>& visited, const int i) {
        if (visited[i] == 1) {
            return 0;
        }
        visited[i] = 1;
        int count = 1;
        for (int j = 0; j < visited.size(); ++j) {
            if (j != i && M[i][j] == 1) {
                count += dns(M, visited, j);
            }
        }
        return count;
    }

    int findCircleNum(std::vector<std::vector<int> >& M) {
        int count = 0;
        std::vector<int> visited(M.size());
        for (int i = 0; i < visited.size(); ++i) {
            int ret = dns(M, visited, i);
            if (ret > 0) {
                ++count;
            }
        }
        return count;
    }
};
