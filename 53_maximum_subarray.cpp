/*************************************************************************************** 
 *
 * 如果当前数字之前的加和大于0，则加上当前数字作为候选；如果当前数字之前的加和小于0，则
 * 无论当前数字正负，加上之后都会变小，所以以当前数字为候选。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max_sum = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (sum > 0) {
                sum = sum + nums[i];
            } else {
                sum = nums[i];
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
