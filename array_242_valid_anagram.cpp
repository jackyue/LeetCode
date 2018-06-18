/*************************************************************************************** 
 *
 * 用两个vector数组保存两个字符串每个字母的出现次数，然后比较两个数组中的字母个数是否完全相同。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::vector<int> s_count;
        std::vector<int> t_count;
        s_count.resize(26);
        t_count.resize(26);
        for (int i = 0; i < s.length(); ++i) {
            ++(s_count[s[i] - 'a']);
        }
        for (int i = 0; i < t.length(); ++i) {
            ++(t_count[t[i] - 'a']);
        }
        for (int i = 0; i < s_count.size(); ++i) {
            if (s_count[i] != t_count[i]) {
                return false;
            }
        }
        return true;
    }
};
