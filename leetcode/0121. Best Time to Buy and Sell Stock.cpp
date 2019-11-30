// 121. Best Time to Buy and Sell Stock.cpp

// at most one transaction

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)	return 0;
        int Min = prices[0], max_profit = 0;
        for (int i = 1; i < len; i++) {
        	max_profit = max(max_profit, prices[i] - Min);
        	Min = min(Min, prices[i]);
        }
        return max_profit;
    }
};