/*************************************************************************************** 
 *
 * 用一棵二叉树求解n个括号的所有合法组合，根节点为"("，左节点添加"("，右节点添加")"。从
 * 树中可以看出，当"("的个数小于n时，可以增加左节点，当"("的个数大于")"时，可以增加右节点。
 * 当"("和")"的个数都等于n时，将拼接好的字符串添加到结果集中。
 * 空间复杂度O(n)。
 *
 ***************************************************************************************/

class Solution {
public:
    void helper(
            const int n, const std::string &parenthesis,
            const int left, const int right, 
            std::vector<std::string> *result) {
        if (left == n && right == n) {
            result->push_back(parenthesis);
            return;
        }
        if (left < n) {
            helper(n, parenthesis + "(", left + 1, right, result);
        }
        if (left > right) {
            helper(n, parenthesis + ")", left, right + 1, result);
        }
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        helper(n, "", 0, 0,  &result);
        return result;
    }
};
