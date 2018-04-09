/*************************************************************************************** 
 *
 * 遍历字符串中的每个字符，由中心向两边扩展。回文子串的长度可能是奇数也可能是偶数。
 * 时间复杂度O(n^2)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    void getPalindromeIndex(
            const std::string &s, const bool is_double, const int i,
            int *length, int *left, int *right) {
        int gap = 1;
        int step = (is_double) ? 1 : 0;
        while (i - gap + step >= 0 && i + gap <= s.length()-1) {
            if (s[i - gap + step] == s[i + gap]) {
                *length = *length + 2;
                *left = i - gap + step;
                *right = i + gap;
            } else {
                break;
            }
            gap++;
        }
    }
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        int max_length = 0;
        int begin = -1;
        int end = -1;
        for (int i = 0; i < s.length(); ++i) {
            int length1 = 1;
            int left1 = i;
            int right1 = i;
            getPalindromeIndex(s, false, i, &length1, &left1, &right1);

            int length2 = 0;
            int left2 = i;
            int right2 = i + 1;
            getPalindromeIndex(s, true, i, &length2, &left2, &right2);

            if (length1 > length2 && length1 > max_length) {
                begin = left1;
                end = right1;
                max_length = length1;
            } else if (length2 > length1 && length2 > max_length) {
                begin = left2;
                end = right2;
                max_length = length2;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};
