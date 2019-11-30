// 123. Best Time to Buy and Sell Stock III.cpp

// at most two transactions

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)	return 0;
        // the max profit if we do one buy sell on or after day i
        vector<int> dpR(len + 1, 0); 

        int Max = prices[len-1], profitMax = 0;
        for (int i = len - 2; i >= 0; i--) {
        	// dpR[i] = max(dpR[i], Max - prices[i]);
        	profitMax = max(Max - prices[i], profitMax);
        	dpR[i] = profitMax;
        	Max = max(prices[i], Max);
        }
        int ans = 0, Min = prices[0];
        profitMax = 0;
        for (int i = 1; i < len; i++) {
        	profitMax = max(profitMax, prices[i] - Min);
        	ans = max(ans, profitMax + dpR[i+1]);
        	Min = min(Min, prices[i]);
        }
        return ans;
    }
};