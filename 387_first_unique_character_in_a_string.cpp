/***************************************************************************************
 *
 * 时间复杂度O()，空间复杂度O()。
 *
 ***************************************************************************************/

class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> count;
        count.resize(26);
        for (int i = 0; i < s.length(); ++i) {
            ++(count[s[i] - 'a']);
        }
        for (int i = 0; i < s.length(); ++i) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
