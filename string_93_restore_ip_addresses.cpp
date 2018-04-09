/*************************************************************************************** 
 *
 * 设置3个字符串断点，判断4个字符串是否为合法数字。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool isValidIpNum(const std::string& str) {
        if (str.empty() || str.length() > 3) {
            return false;
        }
        if (str.length() > 1 && str[0] == '0') {
            return false;
        }
        if (atoi(str.c_str()) > 255) {
            return false;
        }
        return true;
    }
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        if (s.empty() || s.length() < 4 || s.length() > 12) {
            return result;
        }
        for (int i = 1; i <= 3 && i < s.size(); ++i) {
            for (int j = i + 1; j <= i + 3 && j < s.size(); ++j) {
                for (int k = j + 1; k <= j + 3 && k < s.size(); ++k) {
                    std::string first = s.substr(0, i);
                    std::string second = s.substr(i, j - i);
                    std::string third = s.substr(j, k - j);
                    std::string fourth = s.substr(k, s.size() - k);
                    if (isValidIpNum(first) && isValidIpNum(second)
                            && isValidIpNum(third) && isValidIpNum(fourth)) {
                        std::string ip = first + "." + second + "." + third + "." + fourth;
                        result.push_back(ip);
                    }
                }
            }
        }
        return result;
    }
};
