/*************************************************************************************** 
 *
 * 循环计算千位/百位/十位/个位的数值，根据罗马数字命名规则判断该数值的输出。用index变量
 * 标记1/10/100对应的罗马字母，index+1则表示5/50/500对应的罗马字母，index+2则表示10/100/1000
 * 对应的罗马字母。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    std::string mulLable(const std::string& lable, const int mul) {
        std::string mul_lable;
        for (int i = 0; i < mul; i++) {
            mul_lable = mul_lable + lable;
        }
        return mul_lable;
    }
    string intToRoman(int num) {
        std::string lable[7] = {"I", "V", "X", "L", "C", "D", "M"};
        
        int index = 6;
        std::string result;
        int mod = 1000;
        while (num > 0) {
            int n = num / mod;
            
            if (n >= 1 && n <= 3) {
                result = result + mulLable(lable[index], n);
            }
            if (n == 4) {
                result = result + lable[index] + lable[index + 1];
            }
            if (n == 5) {
                result = result + lable[index + 1];
            }
            if (n >= 6 && n <= 8) {
                result = result + lable[index + 1] + mulLable(lable[index], n - 5);
            }
            if (n == 9) {
                result = result + lable[index] + lable[index + 2];
            }
            
            num = num - n * mod;
            mod = mod / 10;
            index = index - 2;
        }
        return result;
    }
};
