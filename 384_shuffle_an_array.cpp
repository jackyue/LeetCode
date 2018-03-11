/*************************************************************************************** 
 *
 ***************************************************************************************/

class Solution {
public:
    Solution(vector<int> nums) {
        m_nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector<int> result;
        if (m_nums.empty()) {
            return result;
        }
        std::vector<int> candidate = m_nums;
        while (candidate.size() > 0) {
            int index = rand() % candidate.size();
            result.push_back(candidate[index]);
            std::vector<int> tmp_vec;
            for (int i = 0; i < candidate.size(); ++i) {
                if (i != index) {
                    tmp_vec.push_back(candidate[i]);
                }
            }
            candidate = tmp_vec;
        }
        return result;
    }
    std::vector<int> m_nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

