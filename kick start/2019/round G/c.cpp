// 2^20 = 1048576

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

void printBit(int a) {
	int bits_len = 8; // sizeof(int) * 8
	int mask = 1 << (bits_len - 1);
	for (int i = 0; i < bits_len; i++) {
		if (a & mask)
			cout << 1 << " ";
		else
			cout << 0 << " ";
		mask >>= 1;
	}
	cout << endl;
}


bool isHappy (vector<int> happy, int map, int val) {
	int mask = 1 << (happy.size() - 1);
	int sum = 0;
	for (int i = 0; i < happy.size(); i++) {
		// printBit(mask);
		if (map & mask) {
			sum += happy[i];
		}
		mask >>= 1;
	}
	// cout << "sum: " << sum << endl;
	return sum >= val;
}

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, h;
		cin >> n >> h;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		int ans = 0, options = 1 << n;
		int mask = options - 1;
		vector<int> a_map, b_map;
		
		for (int i = 0; i < options; i++) {
			if (isHappy(a, i, h))
				a_map.push_back(i);
			if (isHappy(b, i, h))
				b_map.push_back(i);
		}
		// printBit(mask);
		// cout << "a_map: " << endl;
		// for (int i = 0; i < a_map.size(); i++) {
		// 	printBit(a_map[i]);
		// }
		// cout << "b_map: " << endl;
		// for (int i = 0; i < b_map.size(); i++) {
		// 	printBit(b_map[i]);
		// }
		for (int i = 0; i < a_map.size(); i++) {
			for (int j = 0; j < b_map.size(); j++) {
				if ((a_map[i] | b_map[j]) == mask) {
					// cout << "***" << endl;
					// printBit(a_map[i]);
					// printBit(b_map[j]);
					// printBit(mask);
					ans++;
				}
			}
		}

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}