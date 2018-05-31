/*************************************************************************************** 
 *
 * 用两个数组保存当前元素的前一部分元素之积和后一部分元素之积。
 * 再次遍历数组，用上一步的两个数据指定位置的两个数之积作为结果。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> nums_forword;
        std::vector<int> nums_backword;
        std::vector<int> result;
        int num = 1;
        for (int i = 0; i < nums.size(); ++i) {
            nums_forword.push_back(num);
            num = num * nums[i];
        }
        num = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            nums_backword.push_back(num);
            num = num * nums[i];
        }
        std::reverse(nums_backword.begin(), nums_backword.end());
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(nums_forword[i] * nums_backword[i]);
        }
        return result;
    }
};
