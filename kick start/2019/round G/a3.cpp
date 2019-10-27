// passed both small test case and large test case
// time complexity: O(nlogn), with checking to avoid some duplicate operations

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int exist[N], reader[N];

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, m, q;
		cin >> n >> m >> q;
		long long ans = 0;
		for (int i = 0; i < n; i++){
			exist[i] = 1;
			reader[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			exist[temp-1] = 0;
		}
		for (int j = 0; j < q; j++) {
			int temp, all;
			cin >> temp;
			if (reader[temp-1] != 0) {
				ans += reader[temp-1];
				continue;
			}
			all = temp;
			int count = 0;
			while (all <= n) {
				count += exist[all-1];
				all += temp;
			}
			reader[temp-1] = count;
			ans += reader[temp-1];
		}
		
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}