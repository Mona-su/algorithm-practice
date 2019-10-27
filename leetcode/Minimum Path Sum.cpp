// 64. Minimum Path Sum.cpp

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0)	return 0;
        int col = grid[0].size();
        if (col == 0)	return 0;

        
    }
};

// idea: DP
// time: O(n^2)
// space: O(n^2)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0)	return 0;
        int col = grid[0].size();
        if (col == 0)	return 0;

        vector<vector<int> > dp(row, vector<int>(col, 1e9));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < col; j++) {
        		if (i - 1 >= 0) {
        			dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
        		}
        		if (j - 1 >= 0) {
        			dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
        		}
        	}
        }

        return dp[row-1][col-1];
    }
};