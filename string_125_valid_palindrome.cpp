/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        std::string str;
        for (int i = 0; i < s.length(); ++i) {
            if (isalnum(s[i])) {
                str += toupper(s[i]);
            }
        }
        std::string str_raw = str;
        std::reverse(str.begin(), str.end());
        if (str == str_raw) {
            return true;
        }
        return false;
    }
};
