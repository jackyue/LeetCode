/*************************************************************************************** 
 *
 ***************************************************************************************/

 class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int small_num = INT_MAX;
        int big_num = INT_MAX;
        for (int num : nums) {
            if (num <= small_num) {
                small_num = num;
            } else if (num <= big_num) {
                big_num = num;
            } else {
                return true;
            }
        }
        return false;
    }
};