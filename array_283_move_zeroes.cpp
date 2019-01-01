/*************************************************************************************** 
 * 时间复杂度O(n)，空间复杂度O(1)。
 ***************************************************************************************/

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int zero_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                std::swap(nums[zero_index], nums[i]);
                ++zero_index;
            }
        }
    }
};
