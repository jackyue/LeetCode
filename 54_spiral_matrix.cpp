/*************************************************************************************** 
 *
 ***************************************************************************************/

class Solution {
public:
    void next(const int direct, int& i, int& j) {
        if (direct == 0) {
            ++j;
        }
        else if (direct == 1) {
            ++i;
        }
        else if (direct == 2) {
            --j;
        }
        else if (direct == 3) {
            --i;
        }
    }
    std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix) {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        std::map<std::string, int> visited;

        int direct = 0;
        int i = 0;
        int j = 0;
        for (int k = 0; k < m * n; ++k) {
            std::string key = std::to_string(i) + "_" + std::to_string(j);
            result.push_back(matrix[i][j]);
            visited[key] = 1;

            int x = i;
            int y = j;
            next(direct, x, y);
            std::string new_key = std::to_string(x) + "_" + std::to_string(y);
            if ((direct == 0 && y > n - 1)
                    || (direct == 1 && x > m - 1)
                    || (direct == 2 && y < 0)
                    || (direct == 3 && x < 0)
                    || visited.find(new_key) != visited.end()) {
                direct = (direct + 1) % 4;
            }
            next(direct, i, j);
        }
        return result;
    }
};
