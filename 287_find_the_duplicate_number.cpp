/*************************************************************************************** 
 *
 ***************************************************************************************/

class Solution {
public:
    int lessCount(std::vector<int>& nums, int mid) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= mid) {
                ++count;
            }
        }
        return count;
    }

    int findDuplicate(std::vector<int>& nums) {
        int n = nums.size() - 1;
        int low = 1;
        int high = n;
        int mid = (low + high) / 2;
        while (low <= high) {
            int less_count = lessCount(nums, mid);
            if (less_count <= mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }
        return low;
    }
};
