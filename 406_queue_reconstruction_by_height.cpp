/*************************************************************************************** 
 *
 * 
 *
 ***************************************************************************************/

class Solution {
public:
    std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>>& people) {
        std::map<int, std::vector<std::pair<int, int> > > people_map;
        for (int i = 0; i < people.size(); ++i) {
            std::pair<int, int> p = people[i];
            int height = p.first;
            int count = p.second;
            if (people_map.find(height) == people_map.end()) {
                std::vector<std::pair<int, int> > people_vec;
                people_vec.push_back(p);
                people_map[height] = people_vec;
            } else {
                std::vector<std::pair<int, int> > people_vec_new;
                std::vector<std::pair<int, int> >& people_vec = people_map[height];
                
                bool has_inserted = false;
                int j = 0;
                for (; j < people_vec.size(); ++j) {
                    if (!has_inserted && count < people_vec[j].second) {
                        people_vec_new.push_back(p);
                        has_inserted = true;
                    }
                    people_vec_new.push_back(people_vec[j]);
                }
                if (count > people_vec[people_vec.size() - 1].second) {
                    people_vec_new.push_back(p);
                }
                people_vec = people_vec_new;
            }
        }
        std::vector<std::pair<int, int> > people_vec_result;
        std::map<int, std::vector<std::pair<int, int> > >::reverse_iterator it;
        for (it = people_map.rbegin(); it != people_map.rend(); ++it) {
            std::vector<std::pair<int, int> > people_vec_new;
            std::vector<std::pair<int, int> > people_vec = it->second;
            int j = 0;
            for (int i = 0; i < people_vec_result.size(); ++i) {
                while (j < people_vec.size() && people_vec[j].second == people_vec_new.size()) {
                    people_vec_new.push_back(people_vec[j]);
                    ++j;
                }
                people_vec_new.push_back(people_vec_result[i]);
            }

            for (; j < people_vec.size(); ++j) {
                people_vec_new.push_back(people_vec[j]);
            }

            people_vec_result.clear();
            people_vec_result = people_vec_new;
        }
        return people_vec_result;
    }
};
