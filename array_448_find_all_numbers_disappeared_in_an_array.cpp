/*************************************************************************************** 
 *
 * 首先对原始数组进行排序。用index标记1到n的位置。
 * 如果遍历到数组某个位置，该位置取值大于index，则将缺少的数值push到结果数组中。
 * 需要注意的是：
 * 1.需要去除掉重复的数值；
 * 2.如果数组最后一个值小于n，则需将缺少的数值push到结果数组中。
 * 时间复杂度O(n)，空间复杂度O(1)。
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
