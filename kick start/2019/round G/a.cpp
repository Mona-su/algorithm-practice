// passed only small test case
// time complexity: O(n^2)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, m, q;
		cin >> n >> m >> q;
		int ans = 0;
		vector<int> torned(m); 
		for (int i = 0; i < m; i++) {
			cin >> torned[i];
		}
		for (int j = 0; j < q; j++) {
			int temp, all;
			cin >> temp;
			ans += n / temp;
			for (int i = 0; i < torned.size(); i++) {
				if (torned[i] % temp == 0)
					ans--;
			}
		}
		
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}