/*************************************************************************************** 
 *
 * 某位置[i,j]的最小和为: [i-1,j]或[i,j-1]的最小和 + [i,j]的值。
 * 首先计算矩阵第一列的最小和，然后依次计算2~n列的最小和。
 * 时间复杂度O(m*n)，空间复杂度O(m)。
 *
 ***************************************************************************************/

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        std::vector<int> min_vec;
        min_vec.resize(grid.size());
        min_vec[0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            min_vec[i] = min_vec[i - 1] + grid[i][0];
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            for (int i = 0; i < grid.size(); ++i) {
                int last_min = (i == 0 ? min_vec[0] : min_vec[i - 1]);
                int curr_min = min_vec[i];
                min_vec[i] = std::min(last_min, curr_min) + grid[i][j];
            }
        }
        return min_vec[min_vec.size() - 1];
    }
};
