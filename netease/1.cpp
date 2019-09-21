// 1.cpp

// 有n个数的数组A，做m次题问
// 每次题问：某个数在数组A中出现的次数
// input：
// 第一行，n和m
// 第二行：n个数
// 接下来的m行：每次题问问的数字
// 输出：每次题问的回答（0到n）

#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> salaries;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (salaries.find(temp) != salaries.end())
			salaries[temp]++;
		else
			salaries[temp] = 1;
	}
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		if (salaries.find(temp) != salaries.end())
			cout << salaries[temp] << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}