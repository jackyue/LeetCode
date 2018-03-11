/*************************************************************************************** 
 *
 * 
 *
 ***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
