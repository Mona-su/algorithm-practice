#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int n, m;
		cin >> n >> m;
		vector<int> nums(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		int index;
		for (int i = -127; i <= 127; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += nums[j] ^ i;
			}
			if (sum <= m)
				index = i;
			// cout << "sum: " << sum << endl;
		}
		cout << "Case #" << Case << ": " << index << endl;
		Case++;
	}

	return 0;
}