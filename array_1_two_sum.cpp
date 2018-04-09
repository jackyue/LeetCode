/*************************************************************************************** 
 *
 * 用一个map保存已经遍历过的数值和下标的映射关系。当遍历到一个新数值时，查找map中是否含
 * 有target需要的另一个数值，如果有则返回。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (num_map.find(other) != num_map.end()) {
                result.push_back(num_map[other]);
                result.push_back(i);
            }
            num_map[nums[i]] = i;
        }
        return result;
    }
};
