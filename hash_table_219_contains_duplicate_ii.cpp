/*************************************************************************************** 
 *
 * 用map保存每个数字出现的位置；对于每个数字，计算相邻位置是否<=k。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::map<int, std::vector<int>> index_map;
        for (int i = 0; i < nums.size(); ++i) {
            if (index_map.find(nums[i]) == index_map.end()) {
                std::vector<int> vec;
                vec.push_back(i);
                index_map[nums[i]] = vec;
            } else {
                std::vector<int>& vec = index_map[nums[i]];
                vec.push_back(i);
            }
        }
        std::map<int, std::vector<int>>::iterator it;
        for (it = index_map.begin(); it != index_map.end(); ++it) {
            std::vector<int> vec = it->second;
            if (vec.size() < 2) {
                continue;
            }
            for (int i = 1; i < vec.size(); ++i) {
                if (vec[i] - vec[i-1] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
