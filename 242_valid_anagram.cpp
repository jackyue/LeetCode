/*************************************************************************************** 
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
