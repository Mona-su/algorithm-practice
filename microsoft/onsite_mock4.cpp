// 44. Wildcard Matching

// Given an input string (s) and a pattern (p), implement wildcard pattern 
// matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// 44. Wildcard Matching

// Given an input string (s) and a pattern (p), implement wildcard pattern 
// matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// 44. Wildcard Matching

// Given an input string (s) and a pattern (p), implement wildcard pattern 
// matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// dp solution
// time: O(mn), in worst case, O(m^2n)
// space: O(mn)
// not very good solution, requires optimization
class Solution{
public:
	bool isMatch(string s, string p) {
		if (p.length() == 0)	return s.length() == 0;
        
        if (p[0] == '*') {
            p.insert(0, 1, 'a');
            s.insert(0, 1, 'a');
        }

		int m = s.length(), n = p.length();
		vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

		dp[0][0] = true;
		for (int i = 1; i < m+1; i++) {
			for (int j = 1; j < n+1; j++) {
				if (p[j-1] == '*') {
					for (int k = i; k >= 0; k--) {
						if (dp[k][j-1]) {
							dp[i][j] = true;
							break;
						}
					}
				}
				else if (p[j-1] == '?') {
					dp[i][j] = dp[i-1][j-1];
				}
				else {
					dp[i][j] = (dp[i-1][j-1] && s[i-1] == p[j-1]);
				}
			}
		}

		return dp[m][n];
	}
};

// seems to be O(m), but doesn't work
class Solution{
public:
	bool isMatch(string s, string p) {
		if (p.length() == 0) {
			if (s.length() == 0)
				return true;
			else
				return false;
		}
		int j = 0;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == '*') {
				int end = i;
				while (end < p.length()) {
					end++;
					if (p[end] == '*' || p[end] == '?') 
						break;
				}
                if (end == p.length())
                    return true;
                string temp = p.substr(i+1, end - i - 1);
				int k;
				for (k = j; k < s.length(); k++) {
					if (temp == s.substr(k, end - i)) {
						i = end - 1;
						j = k + end - i;
						break;
					}
				}
				if (k == s.length()) 
					return false;
			}
			else if (p[i] == '?') {
				j++;
			}
			else {
				if (j > s.length())
					return false;
				if (p[i] != s[j])
					return false;
				j++;
			}
		}
		if (j == s.length())
			return true;
		else 
			return false;
	}
};