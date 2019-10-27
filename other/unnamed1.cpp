// unnamed1.cpp
#include <iostream>
#include <vector>
using namespace std;

// return 0 if there's no solution exist
int solution (vector <int> a) {
	int min, len = a.size();

	if (len == 0)
		return 0;

	// cout << "size of a: " << len << endl;
	min = a[0];
	for (int i = 0; i < len; i++) {
		min = (a[i] < min) ? a[i] : min;
		// cout << "min: " << min << endl;
	} 

	vector<int> temp(len, 0);

	for (int i = 0; i < len; i++) {
		if (a[i] - min < len) {
			temp[a[i]-min] = 1;
		}
	}

	for (int i = 1; i < len; i++) {
		if (temp[i] == 0 && temp[i-1] == 1)
			return i-1+min;
	}

	return 0;
}

int main(){
	vector <int> a;
	int len, input;
	cin >> len;
	while (len--) {
		cin >> input;
		a.push_back(input);
	}

	int sol = solution(a);
	cout << sol;
	return 0;
}