// 2-4.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max_sub (vector<int> state, int start, int end) {
	if (end <= start)
		return 0;
	else if (end - start == 1) {
		return state[start]*state[start];
	}

	int half = (start + end)/2;
	int left = find_max_sub(state, start, half);
	int right = find_max_sub(state, half, end);

	int mid = 0, min = 0;
	for (int i = half; i < end; ++i)
	{
		/* code */
	}
}

int find_max_sub (vector<int> state) {
	int min, sum, max = 0;
	for (int i = 0; i < state.size(); i++) {
		min = i;
		for (int j = i; j < state.size(); j++) {
			sum += state[j];
			min = (state[min] < state[j]) ? min : j;
			max = (max > sum*state[min]) ? max : (sum*state[min]);
		}
		sum = 0;
	}
	return max;
}

int main(){
	int n; 
	cin >> n;

	vector<int> state(n);
	for (int i = 0; i < n; i++) {
		cin >> state[i];
	}

	// int ans = find_max_sub(state, 0, n);
	// int ans = find_max_sub(state);

	vector<int> dp(n);
	vector<int> min(n);
	dp[0] = state[0]*state[0];
	min[0] = state[0];

	for (int i = 1; i < n; i++) {

	}

	cout << ans << endl;
	return 0;
}