/*************************************************************************************** 
 *
 * 
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
