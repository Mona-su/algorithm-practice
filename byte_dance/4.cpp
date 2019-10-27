// 4.cpp

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= pow(n, 0.5); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool hasCofactor (vector<int> a, vector<int> b) {
	int ai = 0, bi = 0;
	while (ai < a.size() && bi < b.size()) {
		if (a[ai] > b[bi]) {
			bi++;
		}
		else if (a[ai] < b[bi]) {
			ai++;
		}
		else {
			return true;
		}
	}
	return false;
}

vector<int> getPrimeFactors(int n) {
	vector<int> ans;
	for (int i = 2; i <= pow(n, 0.5); i++) {
		if (n % i == 0 && isPrime(i)) {
			ans.push_back(i);
		}
	}
	return ans;
}

int find(vector<int>& parents, int a) {
	while (parents[a] != a) {
		parents[a] = parents[parents[a]];
		a = parents[a];
	}
	return a;
}

void unionTwo(vector<int>& parents, int a, int b){
	int aroot = find(parents, a);
	int broot = find(parents, b);
	if (a != b) {
		parents[a] = broot;
	}
}

int main(){
	int n;
	cin >> n;

	if (n <= 1){
		cout << n << endl;
		return 0;
	}

	vector<int> candies(n);
	vector<vector<int> > primeFactors (n, vector<int>());
	for (int i = 0; i < n; i++) {
		cin >> candies[i];
		primeFactors[i] = getPrimeFactors(candies[i]);
	}

	vector<int> parents(n);
	for (int i = 0; i < n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && hasCofactor(primeFactors[i], primeFactors[j])) {
				unionTwo(parents, i, j);
			}
		}
	}
	vector<int> ans (n, 0);
	for (int i = 0; i < n; i++) {
		ans[find(parents, i)]++;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		max = (max < ans[i]) ? ans[i] : max;
	}
	cout << max << endl;
	return 0;
}