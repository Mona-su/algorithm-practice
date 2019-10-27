// 2-5.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval
{
	int ai, bi;
};

int main(){
	int t, k;
	cin >> t >> k;

	vector<interval> intervals(t);
	int max = 0;

	for (int i = 0; i < t; i++) {
		cin >> intervals[i].ai >> intervals[i].bi;
		max = (max > intervals[i].bi) ? max : intervals[i].bi;
	}

	vector<int> dp(max+1, 1);
	if (k == 0) {
		for (int i = 1; i < max+1; i++) {
			dp[i] = 1;
		}
	}
	else if (k == 1) {
		for (int i = 1; i < max+1; i++) {
			dp[i] = 2^i;
		}
	}
	else {
		for (int i = 1; i < max+1; i++) {
			dp[i] = 0;
			if (i < k) {
				dp[i] = 1;
			}
			else {
				// for (int j = 1; j < k; j++) {
				// 	dp[i] += dp[i-j];
				// }
				dp[i] += dp[i-k] + dp[i-1];
			}
		}
	}

	// print for debug
	for (int i = 1; i < max+1; ++i)
	{
		cout << "dp[" << i << "]: " << dp[i] << endl;
	}

	for (int i = 0; i < t; i++) {
		int ans = 0;
		for (int j = intervals[i].ai; j <= intervals[i].bi; j++) {
			ans += dp[j];
		}
		cout << ans << endl;
	}

	return 0;
}