/*************************************************************************************** 
 *
 * 1.去除字符串前面的空格。
 * 2.判断首字母是否有符号。
 * 3.遍历剩余字符，判断是否是数字，如果是则累加，否则结束遍历。
 * 4.遍历过程中，如果加和超过INT_MAX则，返回INT_MAX或者INT_MIN。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int i = 0;
        bool is_positive = true;
        while (str[i] == ' ') {
            ++i;
        }
        if (str[i] == '-') {
            is_positive = false;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        long long num = 0;
        for (; i < str.length(); ++i) {
            char ch = str[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else {
                break;
            }
            if (num > INT_MAX) {
                return is_positive ? INT_MAX : INT_MIN;
            }
        }
        num = is_positive ? num : (0 - num);
        return num;
    }
};
