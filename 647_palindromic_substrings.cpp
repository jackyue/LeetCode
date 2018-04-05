/*************************************************************************************** 
 *
 * 遍历字符串，每个字符认为是一个回文。
 * 以该字符作为回文中心字符，左右各扩展一个位置，判断字符是否相同。
 * 以该字符作为回文左位置字符，右位置向后移动一个位置，判断字符是否相同。
 * 时间复杂度O(n2)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int countSubstrings(std::string s) {
        if (s.empty()) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++count;
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    ++count;
                } else {
                    break;
                }
                --left;
                ++right;
            }
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    ++count;
                } else {
                    break;
                }
                --left;
                ++right;
            }
        }
        return count;
    }
};
