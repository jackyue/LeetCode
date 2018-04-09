/*************************************************************************************** 
 *
 * 遍历字符串，累加字符对应的数值。若当前字符对应的数值大于前一个，则做减法操作。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int romanToInt(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int result = 0;
        std::unordered_map<char, int> roman_map;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
        int last = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            int num = roman_map[ch];
            result = result + num;
            if (num > last) {
                result = result - 2 * last;
            }
            last = num;
        }
        return result;
    }
};
