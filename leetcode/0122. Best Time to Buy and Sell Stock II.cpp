// 122. Best Time to Buy and Sell Stock II.cpp

// multiple transactions

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2)	return 0;
        int Min = prices[0], all_profit = 0;
        prices.push_back(0);
        for (int i = 1; i < len + 1; i++) {
        	if (prices[i] < prices[i-1]) {
        		all_profit += prices[i-1] - Min;
        		Min = prices[i];
        	}
        }
        return all_profit;
    }
};