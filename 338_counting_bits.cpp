/*************************************************************************************** 
 *
 ***************************************************************************************/

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> result;
        for (int i = 0; i <= num; ++i) {
            int count = 0;
            int n = i;
            while (n > 0) {
                int mod = n % 2;
                if (mod == 1) {
                    ++count;
                }
                n = n / 2;
            }
            result.push_back(count);
        }
        return result;
    }
};
