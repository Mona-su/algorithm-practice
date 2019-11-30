// 45. Jump Game II.cpp

// time: O(n*c)?
// space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();

        if (len <= 1)	return 0;

        int ans = 0, pos = 0, max, index;

        for (int i = 0; i < len; i++) {
        	ans++;
        	if (nums[i] + pos >= len-1) {
        		break;
        	}
        	max = 0;
        	for (int j = 1; j <= nums[i]; j++) {
        		if (i + j + nums[i+j] > max) {
        			max = i + j + nums[i+j];
        			index = i+j;
        		}
        	}
        	pos = index;
        	i = pos - 1;
        }

        return ans;
    }
};

// time: O(n^2), too large!
// space: O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();

        if (len <= 1)	return 0;

        vector<int> dp(len, 1e9);
        dp[0] = 0;
        for (int i = 1; i < len; i++) {
        	for (int j = 1; j <= i; j++) {
        		if (nums[i-j] >= j) {
        			dp[i] = min(dp[i-j] + 1, dp[i]);
        		}
        	}
        }
        return dp[len-1];
    }
};