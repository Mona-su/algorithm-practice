// passed only small test case
// time complexity: O(nlogn)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, m, q;
		cin >> n >> m >> q;
		int ans = 0;
		vector<int> torned(m), pages(n, 0); 
		for (int i = 0; i < m; i++) {
			cin >> torned[i];
		}
		for (int j = 0; j < q; j++) {
			int temp, all;
			cin >> temp;
			all = temp;
			while (all <= n) {
				pages[all-1]++;
				all += temp;
			}
		}
		for (int i = 0; i < m; i++) {
			pages[torned[i]-1] = 0;
		}
		for (int i = 0; i < n; i++)
			ans += pages[i];
		
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}