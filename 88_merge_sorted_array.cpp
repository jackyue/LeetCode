class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> vec;
        vec.insert(vec.end(), nums1.begin(), nums1.begin() + m);
        vec.insert(vec.end(), nums2.begin(), nums2.begin() + n);
        std::sort(vec.begin(), vec.end());
        nums1 = vec;
    }
};
