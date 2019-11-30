// 322. Coin Change.cpp

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coinCategory = coins.size();
        if (coinCategory == 0)	return -1;
        vector<int> dp(amount + 1, 1e9*2);

        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
        	for (int j = 0; j < coinCategory; j++) {
        		if (i - coins[j] >= 0) {
        			dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        		}
        	}
        }
        if (dp[amount] >= 1e9*2)
        	dp[amount] = -1;
        return dp[amount];
    }
};