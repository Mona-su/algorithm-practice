// B_Energy_Stones.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stone{
	int s, e, l;
	int remianing;
};

bool compare (Stone a, Stone b) {
	return a.remianing > b.remianing;
}

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int N;
		cin >> N;
		vector<Stone> stones(N);
		Stone dummy;
		for (int i = 0; i < N; i++) {
			cin >> dummy.s >> dummy.e >> dummy.l;
			dummy.remianing = dummy.e;
			stones[i] = dummy;
		}
		
		
		sort(stones.begin(), stones.end(), compare);
		// cout << "sorting input by energy: " << endl;
		// for (int i = 0; i < N; i++) {
		// 	cout << stones[i].remianing << " ";
		// }
		// cout << endl;
		int ans = stones[0].remianing;
		// cout << "*" << ans << endl;
		int time = stones[0].s;
		int counter = 1
		;

		while (counter < N) {
			for (int i = counter; i < N; i++) {
				stones[i].remianing = stones[i].e - time * stones[i].l;
			}
			sort(stones.begin() + counter, stones.end(), compare);
			if (stones[counter].remianing <= 0)
				break;
			else {
				ans += stones[counter].remianing;
				// cout << "*" << stones[counter].remianing << endl;;
				time += stones[counter].s;
			}
			counter++;
		}
		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}
	return 0;
}