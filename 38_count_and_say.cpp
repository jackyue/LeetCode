/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    string countAndSay(string seq) {
        string result = "";
        int count = 1;
        for (int i = 0; i < seq.length(); ++i) {
            if (i == seq.length() - 1 || seq[i] != seq[i+1]) {
                result += '0' + count;
                result += seq[i];
                count = 1;
            } else {
                ++count;
            }
        }
        return result;
    }
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return countAndSay(countAndSay(n-1));
    }
};
