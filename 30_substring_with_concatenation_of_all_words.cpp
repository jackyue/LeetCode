/*************************************************************************************** 
 *
 * 暴力破解，时间复杂度O(m*n)，也可以用KMP等算法
 *
 ***************************************************************************************/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;
        if (s.length() == 0 || words.size() == 0) {
            return result;
        }
        int words_count = words.size();
        int word_length = words[0].size();
        std::unordered_map<std::string, int> words_map;
        std::unordered_map<std::string, int> count_map;
        for (uint32_t i = 0; i < words.size(); ++i) {
            std::string word = words[i];
            if (words_map.find(word) != words_map.end()) {
                int &count = words_map[word];
                ++count;
            } else {
                words_map[word] = 1;
            }
        }
        int total_length = words_count * word_length;
        for (uint32_t i = 0; i < s.length(); ++i) {
            if (s.length() - i < total_length) {
                break;
            }
            std::string substr = s.substr(i, word_length);
            uint32_t j = i;
            uint32_t found_count = 0;
            while (words_map.find(substr) != words_map.end()) {
                if (count_map.find(substr) == count_map.end()) {
                    count_map[substr] = 1;
                } else {
                    int &count = count_map[substr];
                    ++count;
                    if (count > words_map[substr]) {
                        break;
                    }
                }
                ++found_count;
                if (found_count == words_count) {
                    result.push_back(i);
                }

                j = j + word_length;
                substr = s.substr(j, word_length);
            }
            count_map.clear();
        }

        return result;
    }
};
