/*************************************************************************************** 
 *
 * 以622474875321为例，首先从后往前找到第一个降序的位置，这里是4的位置，然后找到4以后比4
 * 大的最小的数，是5，交换4和5之后变为622475874321，最后翻转5以后的数，变为622475123478
 * 
 * 时间复杂度O(n)，空间复杂度O(1)
 *
 ***************************************************************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int index = -1;
        int value = 0;
        int right = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            int left = nums[i];
            if (left < right) {
                index = i;
                value = left;
                break;
            }
            right = left;
        }

        if (index < 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int change_value = INT_MAX;
        int change_index = -1;
        for (int i = nums.size() - 1; i > index; i--) {
            if (nums[i] > value) {
                if (nums[i] < change_value) {
                    change_value = nums[i];
                    change_index = i;
                }
            }
        }
        nums[index] = change_value;
        nums[change_index] = value;
        std::reverse(nums.begin() + index + 1, nums.end());
    }
};
