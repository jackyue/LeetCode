/*************************************************************************************** 
 *
 * 暴力破解，时间复杂度O(m*n)，也可以用KMP等算法
 *
 ***************************************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_length = haystack.length();
        int needle_length = needle.length();
        if (needle_length == 0) {
            return 0;
        }
        if (needle_length > haystack_length) {
            return -1;
        }
        for (int i = 0; i < haystack_length; ++i) {
            if (i + needle_length <= haystack_length) {
                std::string sub_str = haystack.substr(i, needle_length);
                if (sub_str == needle) {
                    return i;
                }
            } else {
                break;
            }
        }
        return -1;
    }
};
