/*************************************************************************************** 
 *
 * 遍历数组中的字符串，查找最后一个不匹配的位置，保留该位置用于下次遍历截止位置。
 * 时间复杂度O(n1+n2+...)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        std::string candidate = strs[0];
        int len = candidate.length();
        for (int i = 1; i < strs.size(); ++i) {
            std::string str = strs[i];
            len = (len < str.length()) ? len : str.length();
            for (int j = 0; j < len; ++j) {
                if (candidate[j] != str[j]) {
                    len = j;
                    break;
                }
            }
            if (len == 0) {
                return "";
            }
        }
        return candidate.substr(0, len);
    }
};
