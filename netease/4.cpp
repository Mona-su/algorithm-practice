// 4.cpp

// a positive integer array nums of length n, and a positive integer B
// we could use 1 unit energy to do one of the following operations:
// 1. increase one of the integers in nums by 1
// 2. decrease one of the integers in nums by 1
// the final array nums must also contain only positive integers
// Q: the minimal units of energy to make nums[0] * nums[1] * .. * nums[n-1] = B

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// don't know why but it passed all test case
// which is not right
int main() {
	int n, B;
	cin >> n >> B;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int ops = 0;
	for (int i = 0; i < n - 1; i++) {
        ops += nums[i] - 1;
    }
    ops += abs(nums[n-1] - B);
    cout << ops << endl;
    return 0;
}