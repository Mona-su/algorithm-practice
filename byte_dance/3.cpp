// 3.cpp

#include <iostream>
#include <vector>

using namespace std;

void printMap(vector<vector<int> >& map) {
	// cout << "entered printMap" << endl;
	for (int i = 0; i < map.size(); i++) {
		// cout << "i = " << i << endl;
		for (int j = 0; j < map.size(); j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void shift(vector<vector<int> >& map, int index, int key) {
	// cout << "entered shift" << endl;
	vector<int> temp(4);
	int count = 0;
	if (key == 1) {
		for (int i = 0; i < 4; i++) {
			temp[i] = map[i][index];
		}
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (temp[i] > 0) {
				map[count][index] = temp[i];
				count++;
			}
		}
		while (count < 4) {
			map[count][index] = 0;
			count++;
		}
	}

	else if (key == 2) {
		for (int i = 0; i < 4; i++) {
			temp[i] = map[i][index];
			// cout << "**" << endl;
		}
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (temp[4-i-1] > 0) {
				map[4-count-1][index] = temp[4-i-1];
				count++;
				// cout << "count: " << count << ", i: " << i << endl;
			}
		}
		while (count < 4) {
			map[4-count-1][index] = 0;
			count++;
		}
		// cout << "done with shift with key = " << key << endl;
	}

	else if (key == 3) {
		for (int i = 0; i < 4; i++) {
			temp[i] = map[index][i];
		}
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (temp[i] > 0) {
				map[index][count] = temp[i];
				count++;
			}
		}
		while (count < 4) {
			map[index][count] = 0;
			count++;
		}
	}

	else {
		for (int i = 0; i < 4; i++) {
			temp[i] = map[index][i];
		}
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (temp[4-i-1] > 0) {
				map[index][4-count-1] = temp[4-i-1];
				count++;
			}
		}
		while (count < 4) {
			map[index][4-count-1] = 0;
			count++;
		}
	}
}

void operate(vector<vector<int> >& map, int key) {
	if (key == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[j][i] == map[j+1][i]){
					int temp = map[j][i]*2;
					map[j][i] = temp;
					map[j+1][i] = 0;
				}
			}
			shift(map, i, key);
		}
	}

	else if (key == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j >= 1; j--) {
				if (map[j][i] == map[j-1][i] && map[j][i] != 0){
					int temp = map[j][i]*2;
					map[j][i] = temp;
					map[j-1][i] = 0;
					// cout << "**" << j << "-" << i << endl;
				}
			}
			// cout << "operated with key = " << key << endl;
			shift(map, i, key);
		}
		// cout << "finished with key = 2" << endl;
		// printMap(map);
	}

	else if (key == 3) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[i][j] == map[i][j+1]){
					int temp = map[i][j]*2;
					map[i][j] = temp;
					map[i][j+1] = 0;
				}
			}
			shift(map, i, key);
		}
	}

	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j >= 1; j--) {
				if (map[i][j] == map[i][j-1]){
					int temp = map[i][j]*2;
					map[i][j] = temp;
					map[i][j-1] = 0;
				}
			}
			shift(map, i, key);
		}
	}
}

int main(){
	int key;
	cin >> key;
	vector<vector<int> > map(4, vector<int>(4));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
		}
	}

	operate(map, key);
	printMap(map);

	return 0;
}

// 4
// 0 0 0 0
// 0 0 2 2
// 0 2 8 8
// 2 4 2 16