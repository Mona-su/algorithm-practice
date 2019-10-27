// round F, 2019, B

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool ACanTeachB(int a, vector<int> b) {
	for (int i = 1; i < b.size(); i++) {
		if (b[i] == a)
			return false;
	}
	return true;
}

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, s;
		cin >> n >> s;
		vector<vector<int>> skills(n, vector<int>());
		for (int i = 0; i < n; i++) {
			int c;
			cin >> c;
			skills[i].push_back(c);
			for (int j = 0; j < c; j++) {
				int temp;
				cin >> temp;
				skills[i].push_back(temp);
			}
			// cout << "**";
			// for (int j = 0; j < skills[i].size(); j++)
			// 	cout << skills[i][j] << " ";
			// cout << endl;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j != i) {
					for (int k = 1; k < skills[i].size(); k++) {
						// cout << "check with " << i + 1 << " and " << j + 1 << endl;
						// cout << "i + 1 skill: " << skills[i][k] << endl;
						// cout << "j + 1 skill: ";
						// for (int m = 1; m < skills[j].size(); m++)
						// 	cout << skills[j][m] << " ";
						// cout << endl;
						if (ACanTeachB(skills[i][k], skills[j])) {
							ans++;
							// cout << i+1 << " could teach " << j+1 << endl;
							break;
						}
					}
				}
			}
		}
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}