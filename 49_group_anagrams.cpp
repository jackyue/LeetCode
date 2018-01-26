/*************************************************************************************** 
 *
 *
 ***************************************************************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string> > result;
        std::unordered_map<std::string, std::vector<std::string> > group_map;
        for (uint32_t i = 0; i < strs.size(); ++i) {
            std::string str_raw = strs[i];
            std::string str = str_raw;
            std::sort(str.begin(), str.end());
            if (group_map.find(str) == group_map.end()) {
                std::vector<std::string> str_vec;
                str_vec.push_back(str_raw);
                group_map[str] = str_vec;
            } else {
                std::vector<std::string>& str_vec = group_map[str];
                str_vec.push_back(str_raw);
            }
        }
        std::unordered_map<std::string, std::vector<std::string> >::iterator group_it;
        for (group_it = group_map.begin(); group_it != group_map.end(); ++group_it) {
            result.push_back(group_it->second);
        }
        return result;
    }
};
