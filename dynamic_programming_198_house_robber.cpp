/*************************************************************************************** 
 *
 * 当遍历到第i个房间时：
 * 假如抢劫第i个房间，则最大值是第i-2房间的最大值加上第i个房间的值。
 * 假如不抢劫第i个房间，则最大值是第i-1个房间的最大值。
 * 因此，递归公式为max_num[i] = std::max(max_num[i - 1], max_num[i - 2] + nums[i - 1]);
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
	std::vector<int> max_num;
        max_num.resize(nums.size() + 1);
        max_num[0] = 0;
        max_num[1] = nums[0];
        for (uint32_t i = 2; i < max_num.size(); ++i) {
            max_num[i] = std::max(max_num[i - 1], max_num[i - 2] + nums[i - 1]);
        }
        return max_num[nums.size()];
    }

};
