// 2-2.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct consumer
{
	int ai, bi;
};

bool compare1 (consumer a, consumer b) {
	if (a.ai == b.ai) {
		return a.bi < b.bi;
	}
	return a.ai > b.ai;
}

bool compare2 (consumer a, consumer b) {
	if (a.bi == b.bi) {
		return a.ai > b.ai;
	}
	return a.ai < b.ai;
}

int main(){
	int n;
	cin >> n;
	vector<consumer> consumers(n);

	for (int i = 0; i < n; i++) {
		cin >> consumers[i].ai >> consumers[i].bi;
	}

	sort(consumers.begin(), consumers.end(), compare1);
	vector<consumer> temp1(n), temp2(n);
	for (int i = 0; i < n; i++) {
		temp1[i].ai = consumers[i].ai;
		temp1[i].bi = consumers[i].bi;
	}

	sort(consumers.begin(), consumers.end(), compare2);
	for (int i = 0; i < n; i++) {
		temp2[i].ai = consumers[i].ai;
		temp2[i].bi = consumers[i].bi;
	}

	int i = 0, j = n-1, ptr = 0;
	while (i < n && ptr < n) {
		if (temp1[i].ai > temp2[n-i-1].bi) {
			consumers[ptr].ai = temp1[i].ai;
			consumers[ptr].bi = temp1[i].bi;
			i++;
		}
		else {
			consumers[ptr].ai = temp2[j].ai;
			consumers[ptr].ai = temp2[j].ai;
			j--;
		}
		ptr++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += consumers[i].ai*(i) + consumers[i].bi*(n-i-1);
	}
	cout << ans << endl;

	return 0;
}