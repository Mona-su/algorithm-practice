// 2.cpp

#include <iostream>
#include <vector>

using namespace std;

// int findPaths (int n) {
// 	if (n == 2) {
// 		return 1;
// 	}
// 	findPaths(n-2);
// }

int main(){
	int n;
	cin >> n;

	if (n == 0){
		cout << 0 << endl;
		return 0;
	}
	else if (n == 2) {
		cout << 1 << endl;
		return 0;
	}

	vector<int> dp(n/2+1, 0);

	dp[0] = 0; 
	dp[1] = 1;
	dp[2] = 2;

	int ans = 0;
	for (int i = 1; i <= n/2; i++) {
		dp[i] = 3*dp[i-1] - dp[i-2];
	}

	// vector<int> par(n/2+1, 0);
	// for(int i = 0; i < n/2; i++) {
	// 	par[i] = i;
	// }
	// vector<int> next(n/2+1, 2);
	// next[0] = 0;
	// next[1] = 1;

	// for (int i = 0; i <= n/2; i++) {
	// 	ans += par[i]*next[n/2-i];
	// }

	cout << dp[n/2] << endl;

	return 0;
}