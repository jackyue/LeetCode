/*************************************************************************************** 
 *
 * 
 *
 ***************************************************************************************/

class Solution {
public:
    int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) {
        int result = 0;
        std::map<int, int> sum_map;

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                ++(sum_map[A[i] + B[j]]);
            }
        }

        for (int k = 0; k < C.size(); ++k) {
            for (int l = 0; l < D.size(); ++l) {
                int target = -1 * (C[k] + D[l]);
                result += sum_map[target];
            }
        }

        return result;
    }
};
