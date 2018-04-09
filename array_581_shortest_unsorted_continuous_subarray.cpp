/*************************************************************************************** 
 *
 * 对原始数据进行排序，原始数组和排序后的数组作对比。
 * 判断左起第一个不相同的元素low，判断右起第一个不相同的元素high。
 * 两个不相同的元素的距离则为结果。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        std::vector<int> nums_sorted = nums;
        std::sort(nums_sorted.begin(), nums_sorted.end());
        int low = 0;
        int high = nums.size() - 1;
        for (low = 0; low < nums.size(); ++low) {
            if (nums[low] != nums_sorted[low]) {
                break;
            }
        }
        for (high = nums.size() - 1; high > low; --high) {
            if (nums[high] != nums_sorted[high]) {
                break;
            }
        }
        return high - low + 1;
    }
};
