#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

// bool isPrime(int num, set<int> factors) {
// 	set<int>::iterator itr;
// 	for (itr = factors.begin(); itr != factors.end(); itr++) {
// 		if (num%(*itr) == 0) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

vector<int> findPrimeFactors(int num) {
	int mid = int(pow(num, 0.5));
	cout << "mid: " << mid << endl;
	vector<int> ans;
	for (int i = 1; i <= mid; i++) {
		if (num % i == 0) {
			ans.push_back(i);
			ans.push_back(num/i);
		}
	}
	return ans;
}

int findOdd(vector<int> nums) {
	int odd = 0;
	for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
		if ((*itr) & 1) {
			odd++;
		}
	}
	return odd;
}

// int countAll(int num) {
// 	if (num <= 0)	return 0;
// 	return pow(2, num) - 1;
// }

int main(){
	int T, Case = 1;
	cin >> T;

	while (Case <= T) {
		int L, R;
		cin >> L >> R;
		int ans = 0;

		for (int i = L; i <= R; i++) {
			vector<int> primeFactors;
			primeFactors = findPrimeFactors (i);
			int odd = findOdd(primeFactors);
			int even = primeFactors.size() - odd;
			// int countOdd = countAll(odd);
			// int countEven = countAll(even);
			// countEven += countOdd*countEven;
			if (abs(odd - even) <= 2) {
				ans++;
			}
		}

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}