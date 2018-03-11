/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static int cmp(const Interval& a, const Interval& b) {
        if (a.start < b.start) {
            return 1;
        } else {
            return 0;
        }
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        std::vector<Interval> result;
        std::sort(intervals.begin(), intervals.end(), cmp);
        for (uint32_t i = 0; i < intervals.size(); ++i) {
            if (!result.empty()) {
                Interval& last_interval = result[result.size() - 1];
                Interval curr_interval = intervals[i];
                if (last_interval.end >= curr_interval.start) {
                    if (last_interval.end < curr_interval.end) {
                        last_interval.end = curr_interval.end;
                    }
                } else {
                    result.push_back(curr_interval);
                }
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};