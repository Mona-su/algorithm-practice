// round F, 2019, C

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> buildMap(vector<int> roads, int v) {
	vector<int> map(v, vector<int>());
	for (int i = 0; i < roads.size(); i++) {
		if (i&1)
			map[roads[i]-1].push_back(roads[i-1]-1);
		else
			map[roads[i]-1].push_back(roads[i+1]-1);
	}
	return map;
}

int main(){
	int T, Case = 1;
	cin >> T;
	while (Case <= T) {
		int v;
		cin >> v;
		cout << "*" << v << endl;
		vector<int> beauty(v);
		for (int i = 0; i < v; i++){
			cin >> beauty[i];
			cout << "*" << beauty[i];
		}
		vector<int> roads(2*(v-1));
		for (int i = 0; i < 2*(v-1); i++)
			cin >> roads[i];
		
		vector<vector<int>> connected = buildMap(roads, v);
		vector<int> illuminatedBeauty = calBeauty(connected, beauty);

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}