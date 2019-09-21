// 3.cpp
// 一个长度为n的数组nums。
// 如果数组满足：for any i in [2, n), if (sum of nums[j]) <= nums[i] for all j = 0 ... i-1
// 则认为数组具有性质A
// 求nums里具有性质A的最长子序列的长度

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		int Max = 1, start = 0, end = 0, sum = 0, maxOfAll = 0;
		while (end < n) {
			sum += nums[end];
			end++;
			if (nums[end] >= sum) {
				Max++;
				maxOfAll = max(Max, maxOfAll);
			}
			else {
				end--;
				sum -= (nums[start] + nums[end]);
				start++;
				Max--;
			}
		}
		cout << maxOfAll << endl;
	}
	return 0;
}