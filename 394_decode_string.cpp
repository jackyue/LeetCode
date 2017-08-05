/*************************************************************************************** 
 *
 * 用两个栈解决该问题，一个栈保存重复次数，一个栈保存需要重复输出的字符串。
 * 需要注意的几点：
 * 1.重复次数可能大于10。
 * 2.多个字符链接时需判断重复次数栈是否为空，若为空则需要把这些字符保存到结果中，否则
 *   作为临时字符串。
 * 3.遇到’[’字符则将重复次数和重复字符串压入两个栈中。遇到’]’字符则需要弹出重复次数，
 *   重复字符串的累加结果也和第二个步骤一样，判断重复次数栈是否为空，若为空则累加结果
 *   放至result字符串末尾；否则累加的结果放至弹出的重复字符串末尾，继续处理。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        std::string result;
        std::stack<std::string> str_sk;
        std::stack<int> reply_sk;
        if (s.length() == 0) {
            return result;
        }
        int reply_times = 0;
        std::string str;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                reply_times = reply_times * 10;
                reply_times = reply_times + (ch - '0');
            } else if (ch == '[') {
                reply_sk.push(reply_times);
                reply_times = 0;
                str_sk.push(str);
                str = "";
            } else if (ch == ']') {
                int reply = reply_sk.top();
                reply_sk.pop();

                if (!reply_sk.empty()) {
                    std::string tmp_str;
                    for (int i = 0; i < reply; ++i) {
                        tmp_str += str;
                    }
                    str = str_sk.top() + tmp_str;
                    str_sk.pop();
                } else {
                    for (int i = 0; i < reply; ++i) {
                        result += str;
                    }
                }
            } else {
                if (!reply_sk.empty()) {
                    str = str + ch;
                } else {
                    result = result + ch;
                }
            }
        }
        return result;
    }
};
