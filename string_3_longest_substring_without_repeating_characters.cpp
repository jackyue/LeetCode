/*************************************************************************************** 
 *
 * 用position数组记录ascii字符的位置（初始化为-1），用start变量记录不重复子串的起始位置（初始化为-1）。
 * 每遍历一个字符s[i]：
 * 1.判断该字符的位置position[s[i]]是否大于等于start，如果是则说明该字符出现过，更新start的位置。
 * 2.计算子串长度i-start+1。
 * 3.更新该字符的位置position[s[i]]。
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int str_length = s.length();
        if (str_length == 0) {
            return 0;
        }
        std::vector<int> position(256, -1);
        int longest_length = 0;
        int start = -1;
        for (int i = 0; i < str_length; ++i) {
            if (position[s[i]] >= start) {
                start = position[s[i]] + 1;
            }
            longest_length = max(longest_length, i - start + 1);
            position[s[i]] = i;
        }
        return longest_length;
    }
};
