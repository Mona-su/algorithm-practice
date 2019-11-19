#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string p) {
	int pLen = p.length();
	vector<int> next(pLen);
	next[0] = -1;
	int k = -1, j = 0;
	while (j < pLen - 1) {
		if (k == -1 || p[j] == p[k]) {
			j++;
			k++;
			if (p[j] != p[k])
				next[j] = k;
			else 
				next[j] = next[k];
		}
		else {
			k = next[k];
		}
	}
	return next;
}

int kpmSearch (string s, string p){  	
	int i = 0, j = 0;
	int sLen = s.length(), pLen = p.length();
	vector<int> next = getNext(p);
	// print next array
	cout << "the next array: " << endl;
	for (int i : next) {
		cout << i << " ";
	}
	cout << endl;

	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
			cout << j << endl;
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main() {
	string s, p;
	s = "ABDABDABDABC";
	p = "ABDABDABC";

	int index = kpmSearch(s, p);
	cout << "find p at position " << index << endl;

	return 0;
}