/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 * 遍历数组，index记录非value的值存放位置。遍历完后，index即为新数组长度。
 *
 ***************************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
