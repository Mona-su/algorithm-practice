// a.cpp
// passed both small and large test cases

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int count[100000] = {0};

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n;
		cin >> n;
		vector<int> dp(n, 0);
		int ans = 0, temp;
		cout << "Case #" << Case << ": ";
		cin >> temp;
		if (temp > 1) {
			dp[0] = 1;
			ans++;
		}
		else if (temp == 1) {
			ans++;
		}
		count[temp]++;
		cout << ans << " ";
		for (int i = 1; i < n; i++) {
			cin >> temp;
			count[temp]++;
			if (temp >= ans + 1) {
				// cout << "dp[i-1]: " << dp[i-1] << "; ans: " << ans << endl;
				if (dp[i-1] == ans) {
					ans++;
					dp[i] = dp[i-1] - count[ans] + 1;
				}
				else {
					dp[i] = dp[i-1] + 1;
				}
			}
			else {
				dp[i] = dp[i-1];
			}
			cout << ans << " ";
		}

		cout << endl;
		Case++;
		fill(count, count+100000, 0);
	}

	return 0;
}