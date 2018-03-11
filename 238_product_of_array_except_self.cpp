/*************************************************************************************** 
 *
 * 
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
