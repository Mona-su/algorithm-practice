// c.cpp
// passed both small and large test cases

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		vector<int> digits(9);
		int count = 0;
		for (int i = 0; i < 9; i++) {
			cin >> digits[i];
			if (digits[i] > 20) {
				if (digits[i] & 1) {
					digits[i] = 21;
				}
				else {
					digits[i] = 20;
				}
			}
			count += digits[i];
		}
		int half = (count + 1) / 2;
		vector<vector<vector<int>>> dp(10, vector<vector<int>>(half+1, vector<int>(11, 0)));
		// int dp[10][half+1][11] = {0};
		dp[9][0][0] = 1;
		count = 0;
		for (int i = 8; i >= 0; i--) {
			for (int j = 0; j < min(half+1, count+1); j++) {
				for (int k = 0; k < 11; k++) {
					for (int m = 0; m <= digits[i] && m+j < half+1; m++) {
						// cout << "i: " << i << ", j: " << j << ", k: " << k << ", m: " << m << endl;
						int remainder = (k + (i + 1) * (2*m - digits[i])) % 11;
						while (remainder < 0)
							remainder = (remainder + 11) % 11;
						if (dp[i+1][j][k] == 1) {
							dp[i][j+m][remainder] = 1;
							// cout << "dp[" << i << "][" << j+m << "][" << remainder << "] = " << dp[i][j+m][remainder] << endl;
						}
					}
				}
			}
			count += digits[i];
		}
		if (dp[0][half][0] == 1) {
			cout << "Case #" << Case << ": " << "YES" << endl;
		}
		else {
			cout << "Case #" << Case << ": " << "NO" << endl;
		}
		Case++;
	}

	return 0;
}