/*************************************************************************************** 
 *
 * 
 *
 ***************************************************************************************/

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::vector<int> result;
    if (nums.empty()) {
        return result;
    }
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int index = 1;
    for (uint32_t i = 0; i < nums.size(); ++i) {
        if (nums[i] > index) {
            for (uint32_t j = index; j < nums[i]; ++j) {
                result.push_back(j);
            }
            index = nums[i];
        }
        ++index;
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
            ++i;
        }
    }
    for (uint32_t i = nums[n - 1] + 1; i <= n; ++i) {
        result.push_back(i);
    }
    return result;
}
