// C_sol2.cpp

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

const int inf = 1e9;

int main() {
	int T, caseCount = 1; 
	cin >> T;

	while (caseCount <= T) {
		// get input
		int N, K;
		cin >> N >> K;
		vector <int> P(N), A(N);

		for (int i = 0; i < N; i++) 
			cin >> P[i];
		for (int i = 0; i < N; i++)
			cin >> A[i];

		cout << "Case #" << caseCount << ": ";

		// sort colors and rearrange positions
		vector<int> temp = A;
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());

		int colorCount = temp.size();
		vector<vector<int> > color(colorCount);

		for (int i = 0; i < N; i++) {
			int index = lower_bound(temp.begin(), temp.end(), A[i]) - temp.begin();
			color[index].push_back(P[i]);
		}
		for (int i = 0; i < colorCount; i++) {
			sort(color[i].begin(), color[i].end());
		}

		// dp[i][j][k]: given the first i colors and the corresponding dogs, the min time to observe j dogs
		vector<vector<vector <int> > > dp(colorCount + 1, vector<vector <int> >(K + 1, vector<int> (2, inf)));

		dp[0][0][0] = 0;
		for (int i = 1; i < colorCount + 1; i++) {
			for (int j = 0; j < K + 1; j++) {
				for (int k = 0; k < 2; k++) {
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
					for (int a = 0; a < color[i-1].size(); a++) {
						if (j - a - 1 >= 0) {
							dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-a-1][k] + color[i-1][a]*2);
							if (k == 0)
								dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-a-1][k] + color[i-1][a]);
						}
					}
				}
			}
		}

		cout << dp[colorCount][K][1] << endl;
		caseCount++;
	}

	return 0;
}