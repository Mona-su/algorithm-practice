// 647. Palindromic Substrings

// Given a string, your task is to count how many palindromic 
// substrings in this string.

// The substrings with different start indexes or end indexes 
// are counted as different substrings even they consist of 
// same characters.

// dp, time O(n^2), space o(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() < 2)	return s.length();

        vector<vector<bool>> possibles(s.length(), vector<bool>(s.length(), false));
        int ans = 0;
        // possibles[0][0] = true;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j+i < s.length(); j++) {
                if (s[j] == s[j+i]) {
                    if (i < 2) {
                        possibles[j][j+i] = true;
                        ans++;
                    }
                    else {
                        possibles[j][j+i] = possibles[j+1][j+i-1];
                        ans += possibles[j][j+i];
                    }
                }
            }
        }
        
        return ans;
    }
};

class Solution {
private:
	int lastOne(string s, int index) {
		vector<int> beginnings(index+1, 0);
		beginnings[index] = 1;
		beginnings[index-1] = (s[index] == s[index-1]);
		int ans;
		for (int i = index; i >= 0; i--) {

		}
	}
public:
    int countSubstrings(string s) {
        if (s.length() < 2)	return s.length();

        int last = 1, curr;
        for (int i = 1; i < s.length(); i++) {
        	curr = last + lastOne(s, i);
        	last = curr;
        }
        return curr;
    }
};