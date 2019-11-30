// 309. Best Time to Buy and Sell Stock with Cooldown

// multiple transactions with at least one day cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length > 1){
            // max profit on day i, 0 means the day before the first given day
            // for state: 0 means not holding stock, 1 means holding stock, 2 not holding stock for more than one day
            int sol[length][3];
            
            // initialization
            sol[0][0] = 0;
            sol[0][1] = -prices[0];
            sol[0][2] = 0;
            
            for (int i = 1; i < length; i++){
                sol[i][0] = max(sol[i-1][0], sol[i-1][1] + prices[i]);
                sol[i][1] = max(sol[i-1][1], sol[i-1][2] - prices[i]);
                sol[i][2] = sol[i-1][0];
            }
            return max(sol[length-1][0], sol[length-1][2]);
        }
        return 0;
    }
};