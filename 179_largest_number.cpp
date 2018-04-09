/*************************************************************************************** 
 * 
 ***************************************************************************************/

class Solution {
public:
    static bool cmp(const std::string& a, const std::string& b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> str_nums;
        for (int i = 0; i < nums.size(); ++i) {
            str_nums.push_back(std::to_string(nums[i]));
        }
        std::sort(str_nums.begin(), str_nums.end(), cmp);
        std::string result;
        for (int i = 0; i < str_nums.size(); ++i) {
            if (result == "" && i != str_nums.size() - 1 && str_nums[i] == "0") {
                continue;
            }
            result += str_nums[i];
        }
        return result;
    }
};
