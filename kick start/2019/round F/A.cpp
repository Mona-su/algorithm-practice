// round F, 2019, A

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, k;
		cin >> n >> k;
		vector<int> walls(n);
		for (int i = 0; i < n; i++) 
			cin >> walls[i];
		
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}