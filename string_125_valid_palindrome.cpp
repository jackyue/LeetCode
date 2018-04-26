/*************************************************************************************** 
 *
 * 用isalnum判断字符串中的字符是否是字母或者数字，经过reverse之后，判断是否和原字符串相同。
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
