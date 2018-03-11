/*************************************************************************************** 
 *
 * 
 *
 ***************************************************************************************/

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;

        if (s.size() < p.size()) {
            return result;
        }

        std::vector<int> ch_count(26);
        for (int i = 0; i < p.size(); ++i) {
            ++ch_count[p[i] - 'a'];
        }

        for (int i = 0; i <= s.size() - p.size(); ++i) {
            std::string sub_str = s.substr(i, p.size());
            std::vector<int> s_ch_count(26);
            for (int j = i; j < i + p.size(); ++j) {
                ++s_ch_count[s[j] - 'a'];
            }
            if (ch_count == s_ch_count) {
                result.push_back(i);
            }
        }

        return result;
    }
};
