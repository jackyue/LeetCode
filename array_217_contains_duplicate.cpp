
/*************************************************************************************** 
 *
 * 另外一种解法：先对数组做快速排序，然后遍历数据判断是否有相同元素。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> nums_set;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums_set.find(nums[i]) == nums_set.end()) {
                nums_set.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
