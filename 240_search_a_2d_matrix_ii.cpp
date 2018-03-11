/*************************************************************************************** 
 *
 ***************************************************************************************/
 
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        if (target < matrix[0][0] || target > matrix.back().back()) {
            return false;
        }
        int m = matrix.size() - 1;
        int n = 0;
        while (m >= 0 && n < matrix[0].size()) {
            if (target < matrix[m][n]) {
                --m;
            } else if (target > matrix[m][n]) {
                ++n;
            } else {
                return true;
            }
        }

        return false;
    }
};
