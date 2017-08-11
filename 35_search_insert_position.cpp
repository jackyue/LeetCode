/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                index = i;
                break;
            } else {
                index++;
            }
        }
        return index;
    }
};
