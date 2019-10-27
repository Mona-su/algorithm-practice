#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Pair{
	int c, d;
};

int find (int tar, vector<int>& parents) {
	// cout << "inside find" << endl;
	while (tar != parents[tar]) {
		parents[tar] = parents[parents[tar]];
		tar = parents[tar];
	}
	return tar;
}

int unionTwo (int p, int q, vector<int>& parents) {
	// cout << "inside unionTwo" << endl;
	int proot = find(p, parents);
	int qroot = find(q, parents);
	if (proot != qroot) {
		parents[proot] = qroot;
		return 0;
	}
	else {
		return 1;
	}
}

int findParts (vector<int>& parents) {
	set<int> parts;
	for (int i = 0; i < parents.size(); i++) {
		parts.insert(find(parents[i], parents));
	}
	// cout << "**" << parts.size() << endl;
	return parts.size();
}

int main(){
	int T, Case = 1;
	cin >> T;

	while (Case <= T) {
		int N, M;
		cin >> N >> M;
		if (N == 1) {
			cout << "Case #" << Case << ": 0" << endl;
			continue;
		}
		vector<Pair> connectedCherries(M);
		for (int i = 0; i < M; i++) {
			cin >> connectedCherries[i].c >> connectedCherries[i].d;
		}

		// cout << "read input" << endl;

		int ans = 0; 
		vector<int> connected;
		int removedBlack = 0;

		for (int i = 0; i < N; i++) {
			connected.push_back(i);
		}

		for (int i = 0; i < M; i++) {
			removedBlack += unionTwo(connectedCherries[i].c - 1, connectedCherries[i].d - 1, connected);
		}
		// cout << "unioned all" << endl;
		int parts = findParts(connected);
		// cout << "parts: " << parts << endl;
		int usedBlack = M - removedBlack;
		ans = usedBlack + 2 * (parts - 1);

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}