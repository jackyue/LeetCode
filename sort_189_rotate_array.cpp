/*************************************************************************************** 
 *
 * 时间复杂度O(nlogn)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return;
        }
        if (k > nums.size()) {
            k = k % nums.size();
        }
        if (k != nums.size()) {
            std::reverse(nums.begin(), nums.end() - k);
        }
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};
