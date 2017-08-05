/*************************************************************************************** 
 *
 * 依此判断头部和尾部数字是否相等。
 * 时间复杂度O(logn)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int div = 1;
        while (x / div >= 10) {
            div = div * 10;
        }
        while (x > 0) {
            int begin = x / div;
            int end = x % 10;
            if (begin != end) {
                return false;
            }
            x = x - begin * div;
            x = x / 10;
            div = div / 100;
        }
        
        return true;
    }
};
