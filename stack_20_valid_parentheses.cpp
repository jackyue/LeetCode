/*************************************************************************************** 
 *
 * 用一个栈解决。遍历完字符串后，栈为空则说明括号字符串合法。
 * 时间复杂度O(n)，空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        std::stack<char> ch_stk;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                ch_stk.push(s[i]);
            }
            if (s[i] == ')') {
                if (!ch_stk.empty() && ch_stk.top() == '(') {
                    ch_stk.pop();
                } else {
                    return false;
                }
            }
            if (s[i] == '}') {
                if (!ch_stk.empty() && ch_stk.top() == '{') {
                    ch_stk.pop();
                } else {
                    return false;
                }
            }
            if (s[i] == ']') {
                if (!ch_stk.empty() && ch_stk.top() == '[') {
                    ch_stk.pop();
                } else {
                    return false;
                }
            }
        }
        if (!ch_stk.empty()) {
            return false;
        }
        return true;
    }
};
