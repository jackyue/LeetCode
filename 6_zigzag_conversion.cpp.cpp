/*************************************************************************************** 
 *
 * 当nRows==6时，zigzag的输出下标值为下面所示。可以发现规律：竖列之间的间隔为2*(nRows -1)，
 * 第一行和最后一行竖列之间没有其他下标值，其他行竖列之间有一个下标值，该下标值距前一个
 * 竖列之间的间隔为2*(nRows-1-i)。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 * 0           10            20
 * 1        9  11        19  21
 * 2      8    12      18    22
 * 3    7      13    17      23
 * 4  6        14  16        24
 * 5           15            25
 *
 ***************************************************************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.length();
        if (length == 0 || numRows <= 1) {
            return s;
        }
        std::string result;
        for (int i = 0; i < numRows; ++i) {
            int index = i;
            while (index < length) {
                result = result + s[index];
                int next = index + 2 * (numRows - 1);
                if (i == 0 || i == numRows-1) {
                    index = next;
                    continue;
                }
                int middle = index + 2 * (numRows - 1 - i);
                if (middle < length) {  
                    result = result + s[middle];
                } else {
                    break;
                }
                index = next;
            }
        }
        return result;
    }
};
