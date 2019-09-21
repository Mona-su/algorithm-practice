// 2.cpp

// 小易有n堆积木，第i堆积木有hi块。小易还有一个容量无限的背包
// 一开始小易站在第一堆积木旁，每次他可以选择以下三种操作中的一种：
// 1. 从背包里拿出一块积木（如果有的话）放到当前这一堆里
// 2. 从当前这一堆里拿出一块积木（如果有的话）放到背包里
// 3. 从当前这一堆走到下一堆
// 开始小易背包里有m块积木。小易希望把这些积木变成严格递增的（h1 < h2 < .. < hn)
// 小易希望知道这是否可能完成
// 所有操作结束后不需要保证背包为空，积木堆可为空
// 输入：
// 第一行：数据组数T
// 对于每组数据，第一行n，m，接下来一行n个数字表示hi
// 输出：
// "YES"或者"NO"

#include <iostream>
#include <vector>

using namespace std;

// not understanding why, but it only passed 30% of cases
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> h(n);
		for (int i = 0; i < n; i++)
			cin >> h[i];

		for (int i = 0; i < n; i++) {
			if (h[i] > i)
				m += (h[i] - i);
			else if (h[i] < i) {
				int diff = i - h[i];
                m -= diff;
				if (m < 0) {
					cout << "NO" << endl;
					break;
				}
			}
		}
		if (m >= 0)
			cout << "YES" << endl;
	}
	return 0;
}

// int main() {
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		int n, m;
// 		cin >> n >> m;
// 		int sum = 0;
// 		bool flag = true;
// 		for (int i = 0; i < n; i++) {
// 			int temp;
// 			cin >> temp;
// 			if (temp > i && flag)
// 				m += temp - i;
// 			else if (temp < i && flag) {
// 				int diff = i - temp;
// 				if (m < diff) {
// 					flag = false;
// 					// for (int j = i; j < n; j++) 
// 					// 	cin >> temp;
// 					cout << "NO" << endl;
// 				}
// 				else {
// 					m -= diff;
// 				}
// 			}
// 		}
// 		// if (sum + m >= n*(n-1)/2)
// 		// 	cout << "YES" << endl;
// 		// else
// 		// 	cout << "NO" << endl;
// 		if (flag)
// 			cout << "YES" << endl;
// 	}
// 	return 0;
// }