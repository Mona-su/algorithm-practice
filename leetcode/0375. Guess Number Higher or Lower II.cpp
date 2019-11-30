// 375. Guess Number Higher or Lower II

// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I'll tell you whether the number I picked 
// is higher or lower.
// However, when you guess a particular number x, and you guess wrong, 
// you pay $x. You win the game when you guess the number I picked.

// need to use dp
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][i] = 0;
            dp[i-1][i] = i;
        }
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                for (int j = i + 1; j - i < k; j++) {
                    dp[i][i+k] = min(dp[i][i+k], j + 1 + max(dp[i][j-1], dp[j+1][i+k]));
                    
                }
                // cout << "dp[" << i << "][" << i+k << "]: " << dp[i][i+k] << endl;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 2; j < n; j++) {
        //         for (int k = i + 1; k < j; k++) {
        //             dp[i][j] = min(dp[i][k-1] + k + 1 + dp[k+1][j], dp[i][j]);
        //         }
        //     }
        // }
        
        return dp[0][n-1];
    }
};