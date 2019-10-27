// C_Diverse_Subarray.cpp

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	int T, Case = 1;
	cin >> T;

	while (Case <= T) {
		int N, S;
		cin >> N >> S;
		vector<int> input(N);
		int dummy;
		for (int i = 0; i < N; i++) {
			cin >> dummy;
			input[i] = dummy;
		}

		int max = 0;
		for (int i = 0; i < N; i++) {
			map<int, int> types;
			types[input[i]] = 1;
			int temp = 1;
			for (int j = i + 1; j < N; j++) {
				if (types.find(input[j]) != types.end()) {
					types[input[j]]++;
				}
				else {
					types[input[j]] = 1;
				}
				if (types[input[j]] == S + 1) {
					temp = temp - types[input[j]] + 1;
				}
				else if (types[input[j]] <= S) {
					temp++;
				}
				// else {
				// 	temp--;
				// }
				max = (temp > max) ? temp : max;
			}
			max = (temp > max) ? temp : max;
			map<int, int>().swap(types);
		}
		cout << "Case #" << Case << ": " << max << endl;
		Case++;
	}

	return 0;
}