// 2-1.cpp

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

	//vector<int> locks(n), keys(m);
	int lock_odd = 0, key_odd = 0, temp, ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp&1) {
			lock_odd++;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (temp&1){
			key_odd++;
		}
	}

	ans += (lock_odd > (m - key_odd)) ? (m - key_odd) : lock_odd;
	ans += (key_odd > (n - lock_odd)) ? (n - lock_odd) : key_odd;

	cout << ans << endl;

	return 0;
}