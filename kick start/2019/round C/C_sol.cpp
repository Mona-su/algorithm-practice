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

		// output for debug
		cout << endl << "color table: " << endl;
		for (int i = 0; i < colorCount; i++) {
			for (int j = 0; j < color[i].size(); j++) {
				cout << setw(6) << color[i][j];
			}
			cout << endl;
		}

		// dp[i][j]: given the first i+1 colors and the corresponding dogs, the min time to observe j+1 dogs
		// endP[i][j]: the ending position when observing j+1 dogs in first i+1 colors
		vector<vector<int> > dp(colorCount, vector<int>(K, inf)), endP(colorCount, vector<int>(K, 0));

		// initialization
		dp[0][0] = color[0][0];
		endP[0][0] = color[0][0];
		for (int i = 1; i < colorCount; i++) {
			dp[i][0] = min(dp[i-1][0], color[i][0]);
			endP[i][0] = dp[i][0];
		}
		for (int i = 1; i < color[0].size(); i++) {
			dp[0][i] = color[0][i];
			endP[0][i] = dp[0][i];
		}

		int dogCount;
		for (int j = 1; j < K; j++) {
			dogCount = color[0].size();
			for (int i = 1; i < colorCount; i++) {
				dogCount += color[i].size();
				if (j < dogCount) {
					dp[i][j] = dp[i-1][j];
					endP[i][j] = endP[i-1][j];
					for (int k = 0; k < color[i].size(); k++) {
						if (j - k - 1 >= 0) {
							if (dp[i-1][j-k-1] + color[i][k] + min(endP[i-1][j-k-1], color[i][k]) < dp[i][j]) {
								dp[i][j] = dp[i-1][j-k-1] + color[i][k] + min(endP[i-1][j-k-1], color[i][k]);
								endP[i][j] = max(endP[i-1][j-k-1], color[i][k]);
							}
						}
						else
							break;
					}
				}
			}
		}

		// output for debug
		cout << endl << "dp table: " << endl;
		for (int i = 0; i < colorCount; i++) {
			for (int j = 0; j < K; j++) {
				if (dp[i][j] == inf) {
					cout << setw(6) << 0;
				}
				else {
					cout << setw(6) << dp[i][j];
				}
			}
			cout << endl;
		}
		cout << endl << "end position table: " << endl;
		for (int i = 0; i < colorCount; i++) {
			for (int j = 0; j < K; j++) {
				cout << setw(6) << endP[i][j];
			}
			cout << endl;
		}

		cout << dp[colorCount-1][K-1] << endl;
		caseCount++;
	}

	return 0;
}