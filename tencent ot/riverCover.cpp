// riverCover.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct guard
{
	int left;
	int right;
};

bool compare (guard a, guard b) {
	return a.right < b.right;
}

int main() {
	int n, L;

	cin >> n >> L;
	vector<guard> guards;
	int first, second;
	guard temp;

	for (int i = 0; i < n; i++) {
		cin >> first >> second;
		temp.left = first;
		temp.right = second;
		guards.push_back(temp);
	}

	cout << "input finished. " << endl;

	sort(guards.begin(), guards.end(), compare);
	cout << "vector sorted. " << endl;
	for (int i = 0; i < n; i++) {
		cout << guards[i].left << " " << guards[i].right << endl;
	}

	int lastIndex = -1; 
	vector <int> selectedGuards;
	for (int i = 0; i < n; i++) {
		if (guards[i].left == 0 && i > lastIndex) {
			vector<int>().swap(selectedGuards);
			selectedGuards.push_back(guards[i].right);
			continue;
 		}

 		for (vector<int>::iterator it = selectedGuards.begin(); it != selectedGuards.end(); it++) {
 			if (guards[i].left <= *it) {
 				it++;
 				selectedGuards.erase (it, selectedGuards.end());
 				selectedGuards.push_back(guards[i].right);
 				break;
 			}
 		}

 		if (*(selectedGuards.end()-1) >= L) {
 			break;
 		} 
 	}

	cout << selectedGuards.size() << endl;

	return 0;
}

