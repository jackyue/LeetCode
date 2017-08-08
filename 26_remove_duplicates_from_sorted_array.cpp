/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int num = nums[0];
        int index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != num) {
                nums[index+1] = nums[i];
                num = nums[i];
                index++;
            }
        }
        return index + 1;
    }
};
