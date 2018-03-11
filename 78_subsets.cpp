/*************************************************************************************** 
 * 
 ***************************************************************************************/

class Solution {
public:
    void traverseNums(
            std::vector<int>& nums,
            std::vector<std::vector<int>>& result,
            int index,
            std::vector<int>& vec) {
        if (index > nums.size() - 1) {
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            vec.push_back(nums[i]);
            result.push_back(vec);
            traverseNums(nums, result, i + 1, vec);
            vec.pop_back();
        }
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;

        std::vector<int> vec;
        result.push_back(vec);

        traverseNums(nums, result, 0, vec);

        return result;
    }
};
