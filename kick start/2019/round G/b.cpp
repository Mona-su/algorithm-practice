#include <iostream>
#include <vector>
#include <set>

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

int carryBits (int a, int b) {
	int bits_len = 8; // sizeof(int) * 8
	int ans = 0, mask = 1 << (bits_len - 2);
	for (int i = 0; i < bits_len - 1; i++) {
		if ((a & mask) && (b & mask)) {
			ans |= (mask << 1);
		}
		mask >>= 1;
	}
	return ans;
}

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
			sum ^= nums[i];
			printBit(nums[i]);
		}
		printBit(sum);
		cout << "sum: " << sum << endl;
		int temp = sum, i;
		for (i = 0; sum <= m; i++) {
			sum = temp;
			if (n & 1)
				sum ^= i;
			for (int j = 0; j < n; j++) {
				sum ^= carryBits(i, nums[j]);
			}
			printBit(sum);
			cout << "sum: " << sum << endl;
			cout << "i: " << i << endl;
		}
		printBit(carryBits(12, 8));
		cout << "Case #" << Case << ": " << i - 1 << endl;
		Case++;
	}

	return 0;
}