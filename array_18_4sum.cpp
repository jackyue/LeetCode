/***************************************************************************************
 *
 * 时间复杂度O(n的3次方)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    void twoSum(
            const std::vector<int> &nums,
            const int target,
            const uint32_t p,
            const int first,
            const int second,
            std::vector<std::vector<int> > *result) {
        int sum = target - first - second;
        int low = p;
        int high = nums.size() - 1;
        while (low < high) {
            int third = nums[low];
            int fourth = nums[high];
            if (third + fourth == sum) {
                std::vector<int> result_vec;
                result_vec.push_back(first);
                result_vec.push_back(second);
                result_vec.push_back(third);
                result_vec.push_back(fourth);
                result->push_back(result_vec);
                while (low < high && nums[low] == nums[low + 1]) {
                    ++low;
                }
                while (low < high && nums[high] == nums[high - 1]) {
                    --high;
                }
                ++low;
                --high;
            } else if (third + fourth > sum) {
                --high;
            } else if (third + fourth < sum) {
                ++low;
            }
        }
    }

    void threeSum(
            const std::vector<int>& nums,
            const int target,
            const uint32_t p,
            const int first,
            std::vector<std::vector<int> >* result) {
        for (uint32_t i = p; i < nums.size() - 2; ++i) {
            if (i > p && nums[i] == nums[i - 1]) {
                continue;
            }
            int second = nums[i];
            twoSum(nums, target, i + 1, first, second, result);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int> > result;
        if (nums.size() < 4) {
            return result;
        }
        std::sort(nums.begin(), nums.end());

        for (uint32_t i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int first = nums[i];
            threeSum(nums, target, i + 1, first, &result);
        }
        return result;
    }
};
