#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
	double c, e;
	double eatToCode;
};

bool compare(Pair a, Pair b) {
	return a.eatToCode < b.eatToCode;
}

char checkFromOrdered (vector<Pair>& sections, int index, Pair day) {
	cout << "index: " << index << endl;
	double code = double(day.c), eat = double(day.e);
	for (int i = 0; i < sections.size(); i++) {
		if (code > 0) {
			code = code - sections[index].c;
			if (code < 0) {
				double f = (0 - code) * 1.0 / sections[index].c;
				eat -= f*sections[index].e;
				if (eat <= 0) {
					return 'Y';
				}
			}
		}
		else if (code <= 0) {
			eat -= sections[index].e;
			if (eat <= 0) {
				return 'Y';
			}
		}
		index = (index-1)%sections.size();
	}
	return 'N';
}

char canFulfill (vector<Pair>& sections, Pair day) {
	if (day.c == 0) {
		int temp = 0;
		for (int i = 0; i < sections.size(); i++) {
			temp += sections[i].e;
			if (temp >= day.e){
				return 'Y';
			}
		}
		return 'N';
	}
	else if (day.e == 0) {
		int temp = 0;
		for (int i = 0; i < sections.size(); i++) {
			temp += sections[i].c;
			if (temp >= day.c){
				return 'Y';
			}
		}
		return 'N';
	}
	else {
		if (day.e*1.0/day.c <= sections[0].eatToCode) {
			return checkFromOrdered (sections, 0, day);
		}
		for (int i = 1; i < sections.size(); i++) {
			if (day.e*1.0/day.c < sections[i].eatToCode) {
				return checkFromOrdered (sections, i-1, day);
			}
		}
		if (day.e*1.0/day.c >= sections[sections.size()-1].eatToCode) {
			return checkFromOrdered (sections, sections.size()-1, day);
		}
		
		// char ans = checkFromOrdered (sections, 0, day);
		// if (ans == 'Y')	return ans;
		// ans = checkFromOrdered (sections, 1, day);
		// return ans;
	}
}

int main(){
	int T, Case = 1;
	cin >> T;

	while (Case <= T) {
		int D, S;
		cin >> D >> S;
		vector<Pair> sections (S);
		vector<Pair> days(D);

		for (int i = 0; i < S; i++) {
			cin >> sections[i].c >> sections[i].e;
			sections[i].eatToCode = sections[i].e*1.0/sections[i].c;
			// cout << "**" << sections[i].eatToCode << endl;
		} 
		for (int i = 0; i < D; i++) {
			cin >> days[i].c >> days[i].e;
		}

		sort(sections.begin(), sections.end(), compare);
		// for (int i = 0; i < S; i++) {
		// 	cout << "**" << sections[i].c << " " << sections[i].e << " " << sections[i].eatToCode << endl;
		// } 

		string ans = "";
		for (int i = 0; i < D; i++) {
			ans += canFulfill(sections, days[i]);
		}

		cout << "Case #" << Case << ": " << ans << endl;
		Case++;
	}

	return 0;
}