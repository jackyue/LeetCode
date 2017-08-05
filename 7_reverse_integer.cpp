/*************************************************************************************** 
 *
 * 逆序求和即可，注意乘数也有可能溢出，所以也需要用long型。
 * 时间复杂度O(logn)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int reverse(int x) {
        long num = 0;
        bool is_positive = true;
        if (x < 0) {
            is_positive = false;
            x = x * -1;
        }
        long div = 1;
        while (x / div >= 10) {
            div = div * 10;
        }
        while (x > 0 && div > 0) {
            long n = x % 10;
            num = num + n * div;
            if (num > INT_MAX) {
                return 0;
            }
            div = div / 10;
            x = x / 10;
        }
        return is_positive ? num : 0 - num;
    }
};
