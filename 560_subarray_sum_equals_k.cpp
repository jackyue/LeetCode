/*************************************************************************************** 
 *
 ***************************************************************************************/

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int result = 0;
        std::vector<int> sums;
        sums.resize(nums.size() + 1);
        sums[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (int i = 0; i < sums.size(); ++i) {
            for (int j = i + 1; j < sums.size(); ++j) {
                int sum = sums[j] - sums[i];
                if (sum == k) {
                    ++result;
                }
            }
        }

        return result;
    }
};
