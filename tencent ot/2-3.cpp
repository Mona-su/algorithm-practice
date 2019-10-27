// 2-3.cpp

/*
n个房间位置为1-n，每个房间的任务数量a[i]，m个工人都在起点0处，每个工人每个单位时间能从
当前位置走到下一个位置，或者完成一个当前房间的任务，请问所有任务完成最短需要多少时间.
样例：n=4,m=100,a={3,4,3,4},输出5，范围：n,m是1-10e5，a[i]是0-10e9
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> blocks(n);
	int sum = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> blocks[i];
		sum += blocks[i];
	}

	if (sum <= m) {
		ans = n+1;
	}
	else {
		int temp = sum/m;
		// int sub_sum = blocks[0], max = 0
		// for (int i = 0, j = 0; i < m && j < n; i++) {
		// 	max = j;
		// 	while (sub_sum <= temp) {
		// 		max += 1 + blocks[j];
		// 		sub_sum += blocks[j];
		// 		j++;
		// 	}
		// 	ans = (ans > max) ? ans : max;
		// 	max = 0;
		// 	sub_sum = 0;
		// }
		if (sum % m == 0)
			ans = n + temp;
		else
			ans = n + temp + 1;
	}

	cout << ans << endl;
	return 0;
}