/*************************************************************************************** 
 *
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0) {
            return b;
        }
        if (b.length() == 0) {
            return a;
        }
        std::string result;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int val_a = a[i] - '0';
            int val_b = b[j] - '0';
            int sum = val_a + val_b + carry;
            if (sum == 3) {
                carry = 1;
                result = "1" + result;
            } else if (sum == 2) {
                carry = 1;
                result = "0" + result;
            } else if (sum == 1) {
                carry = 0;
                result = "1" + result;
            } else {
                carry = 0;
                result = "0" + result;
            }
            --i;
            --j;
        }
        while (i >= 0) {
            int val_a = a[i] - '0';
            int sum = val_a + carry;
            if (sum == 2) {
                carry = 1;
                result = "0" + result;
            } else if (sum == 1) {
                carry = 0;
                result = "1" + result;
            } else {
                carry = 0;
                result = "0" + result;
            }
            --i;
        }
        while (j >= 0) {
            int val_b = b[j] - '0';
            int sum = val_b + carry;
            if (sum == 2) {
                carry = 1;
                result = "0" + result;
            } else if (sum == 1) {
                carry = 0;
                result = "1" + result;
            } else {
                carry = 0;
                result = "0" + result;
            }
            --j;
        }
        if (carry == 1) {
            result = "1" + result;
        }
        return result;
    }
};
