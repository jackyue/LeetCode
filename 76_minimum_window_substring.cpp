/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int t_times[255] = {0};
        int s_times[255] = {0};
        for (uint32_t i = 0; i < t.length(); ++i) {
            t_times[t[i]]++;
        }

        int begin = -1;
        int end = s.length();
        int start = 0;
        int found = 0;
        int min_length = s.length();
        for (uint32_t i = 0; i < s.length(); ++i) {
            char ch = s[i];
            s_times[ch]++;
            if (s_times[ch] <= t_times[ch]) {
                ++found;
            }
            if (found == t.length()) {
                while (start < i && s_times[s[start]] > t_times[s[start]]) {
                    s_times[s[start]]--;
                    ++start;
                }
                if (i - start < min_length) {
                    min_length = i - start;
                    begin = start;
                    end = i;
                }
                s_times[s[start]]--;
                ++start;
                --found;
            }
        }
        if (begin == -1) {
            return "";
        } else {
            return s.substr(begin, end - begin + 1);
        }
    }
};

