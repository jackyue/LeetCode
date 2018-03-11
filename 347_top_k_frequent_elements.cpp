/*************************************************************************************** 
 *
 ***************************************************************************************/

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::map<int, int> key_map;
        for (int i = 0; i < nums.size(); ++i) {
            ++key_map[nums[i]];
        }
        std::set<int> freq_set;
        std::map<int, std::vector<int> > count_map;
        std::map<int, int>::iterator it;
        for (it = key_map.begin(); it != key_map.end(); ++it) {
            int key = it->first;
            int count = it->second;
            freq_set.insert(count);
            if (count_map.find(count) == count_map.end()) {
                std::vector<int> key_vec;
                key_vec.push_back(key);
                count_map[count] = key_vec;
            } else {
                std::vector<int>& key_vec = count_map[count];
                key_vec.push_back(key);
            }
        }

        int k_count = 0;
        std::set<int>::reverse_iterator set_it = freq_set.rbegin();
        for (; set_it != freq_set.rend(); ++set_it) {
            std::vector<int> key_vec = count_map[*set_it];
            for (int j = 0; j < key_vec.size(); ++j) {
                result.push_back(key_vec[j]);
                ++k_count;
                if (k_count == k) {
                    return result;
                }
            }
        }

        return result;
    }
};

