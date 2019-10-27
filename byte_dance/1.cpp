// 1.cpp
#include <iostream>
#include <vector>
#include <set>
// #include <stdlib.h>

using namespace std;

void dfs (vector<vector<int> >& map, int row, int& count) {
	count--;
	for (int i = 0; i < map.size(); i++) {
		if (map[row][i] >= 3) {
			map[row][i] = count;
			if (i != row){
				// cout << "**" << row << "-" << i << endl;
				count++;
				dfs(map, i, count);
			}
		}
		else if (map[row][i] < 0) {
			break;
		}
	}
}

int getGroups (vector<vector<int> >& map) {
	set<int> nums;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			if (map[i][j] < 0)
				nums.insert(map[i][j]);
		}
	}
	return nums.size();
}

void printMap(vector<vector<int> > map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int N; 
	cin >> N;

	if (N < 2) {
		cout << N << endl;
		return 0;
	}

	vector<vector<int> > map(N, vector<int>(N, 3));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (i == j) {
				map[i][j] = 3;
			}
		}
	}

	// printMap(map);

	int count = 0;

	for (int i = 0; i < N; i++) {
		dfs(map, i, count);
	}
	// printMap(map);

	cout << getGroups(map) << endl;

	return 0;
}