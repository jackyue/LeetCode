
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> nums_set;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums_set.find(nums[i]) == nums_set.end()) {
                nums_set.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};