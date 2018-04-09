/*************************************************************************************** 
 *
 * 回溯
 *
 ***************************************************************************************/

class Solution {
public:
    void SearchSolutions(const std::vector<int>& candidates,
            const int target, int sum, int index,
            std::vector<int> candidate,
            std::vector<std::vector<int> > *result) {
        for (uint32_t i = index; i < candidates.size(); ++i) {
            sum = sum + candidates[i];
            candidate.push_back(candidates[i]);
            if (sum == target) {
                result->push_back(candidate);
                return;
            } else if (sum > target) {
                candidate.pop_back();
                return;
            }
            SearchSolutions(candidates, target, sum, i, candidate, result);
            sum = sum - candidates[i];
            candidate.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int> > result;
        std::vector<int> candidate;
        std::sort(candidates.begin(), candidates.end());
        SearchSolutions(candidates, target, 0, 0, candidate, &result);
        return result;
    }
};
