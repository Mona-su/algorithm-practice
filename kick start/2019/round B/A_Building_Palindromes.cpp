// A. Building Palindromes.cpp

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// return 0 if can't, 1 otherwise
// int canFormPalindrome (string input, int left, int right) {
// 	if (right - left == 0)	return 1;

// 	vector<int> chars(26, 0);
// 	int oddCount = 0;
// 	// cout << "**";
// 	for (int i = left; i <= right; i++) {
// 		chars[input[i]-'A']++;
// 		if (chars[input[i]-'A'] & 1) {
// 			oddCount++;
// 		}
// 		else {
// 			oddCount--;
// 		}
// 		// cout << input[i];
// 	}
// 	// cout << endl;

// 	return (oddCount > 1) ? 0 : 1;
// }

int countBit (long input) {
	int count = 0;
    // cout << input;
    for (int i = 0; i < 26; i++){
        if (input&1){
            count++;
        }
        input = input >> 1;
    }
    return count;
}

void changeBit(long& a, int i) {
	long flag = 1;
	for (int j = 0; j < i; j++) {
		flag <<= 1;
	}
	a |= flag;
}

long formBitmap (string input, long prev, char curr) {
	long temp = 0;
	int i = input[curr] - 'A';
	changeBit(temp, i);
	return temp^prev;
}

void printBit(long a) {
	for (int i = 0; i < 26; i++) {
		if (a&1){
			cout << 1;
		}
		else 
			cout << 0;
		a >>= 1;
	}
	cout << endl;
}

int main(){
	int T; 
	cin >> T;
	int Case = 1;
	while (Case <= T) {
		int N, Q;
		cin >> N >> Q;
		string input; 
		cin >> input;

		vector<long> chars(N, 0);
		long prev = 0;
		for (int i = 0; i < N; i++) {
			chars[i] = formBitmap(input, prev, i);
			prev = chars[i];
			// printBit(chars[i]);
		}

		int li, ri, ans = 0, odd;
		for (int i = 0; i < Q; i++) {
			cin >> li >> ri;
			odd = countBit(chars[ri-1]^chars[li-2]);
			// cout << "**odd: " << odd << endl;
			ans += (odd > 1) ? 0 : 1;
			// ans += canFormPalindrome(input, li-1, ri-1);
		}

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}