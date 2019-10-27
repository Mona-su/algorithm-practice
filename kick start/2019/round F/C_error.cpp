// round F, 2019, C

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int find_upper(int val, vector<int> roads) {
	cout << "entered find_upper" << endl;
	for (int i = roads.size() - 1; i >= 0; i--)
		if (roads[i] == val)
			return i;
	cout << "returned -1 in find_upper" << endl;
	return -1;
}

int findHead(vector<int>& roads, int v) {
	cout << "entered findHead" << endl;
	vector<int> count(v, 0);
	for (int i = 0; i < roads.size(); i++)
		count[roads[i]-1]++;
	for (int i = 0; i < v; i++)
		if (count[i] == 1)
			return i+1;
	cout << "returned -1 in findHead" << endl;
	return -1;
}

vector<int> orderVillages(int head, vector<int> roads) {
	int i = find_upper(head, roads), upper = -1;
	vector<int> ordered;
	ordered.push_back(head);
	while (1) {
		i = (i&1) ? (i-1) : (i+1);
		upper = find_upper(roads[i], roads);
		cout << "**" << roads[upper] << endl;
		roads.push_back(roads[upper]);
		if (upper == i)
			break;
		i = upper;
	}
	return ordered;
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
		cout << "2*(v-1): " << 2*(v-1) << endl;
		for (int i = 0; i < 2*(v-1); i++)
			cin >> roads[i];
		cout << "*" << endl;
		int head = findHead(roads, v);
		vector<int> connected_village = orderVillages(head, roads);
		cout << "length of connected_village: " << connected_village.size() << endl;
		int ans = 0;
		bool prev = false; // whether the previous house is illuminated or not
		// beauty.insert(beauty.begin(), 0);
		// connected_village.insert(connected_village.begin(), 0);
		// connected_village.push_back(0);
		for (int i = 1; i < v; i++) {
			int sum = 0;
			if (i-1 >= 0)
				sum += beauty[connected_village[i-1]-1];
			if (i+1 < connected_village.size())
				sum += beauty[connected_village[i+1]-1];
			if (sum <= 0) {
				prev = false;
				continue;
			}
			if (!prev){
				prev = true;
				ans += sum;
				continue;
			}
			else {
				int bothOn = 0, currOn = 0;
				if (i+1 < connected_village.size()) {
					bothOn = beauty[connected_village[i+1]-1];
					if (i-2 >= 0)
						currOn = beauty[connected_village[i+1]-1] - beauty[connected_village[i-2]-1];
				}
				int Max = max(bothOn, currOn);
				if (Max <= 0)
					prev = false;
				else {
					prev = true;
					ans += Max;
				}
			}
		}

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}