// b.cpp

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n;
		cin >> n;
		vector<vector<char>> map(n, vector<char>(n));
		int dots = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.') 
					dots++;
			}
		}
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}