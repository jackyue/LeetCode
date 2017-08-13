/*************************************************************************************** 
 *
 * 题意是把字符串按空格进行split，取最后一个单词的长度
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int result = 0;
        int i = s.length() - 1;
        while (i >= 0) {
            if (s[i] == ' ' && result > 0) {
                break;
            }
            if (s[i] != ' ') {
                result++;
            }
            i--;

        return result;
    }
};
