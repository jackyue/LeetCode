/*************************************************************************************** 
 *
 * 找到数组中最大差值的两个数。
 * 时间复杂度O(n)，空间复杂度O(1)。
 *
 ***************************************************************************************/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int max_profit = 0;
        int min = prices[0];
        for (uint32_t i = 1; i < prices.size(); ++i) {
            // 更新买入价
            if (prices[i] < min) {
                min = prices[i];
            }
            // 当前价格高于买入价并且差值大于最大利润则更新最大利润
            if (prices[i] > min
                    && prices[i] - min > max_profit) {
                max_profit = prices[i] - min;
            }
        }
        return max_profit;
    }
};
