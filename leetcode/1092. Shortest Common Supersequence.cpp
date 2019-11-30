// 1092. Shortest Common Supersequence

// Given two strings str1 and str2, return the shortest string 
// that has both str1 and str2 as subsequences.  If multiple answers 
// exist, you may return any of them.

// pointer error, haven't done yet
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if (str1.length() == 0)	return str2;
        if (str2.length() == 0)	return str1;

        int l1 = str1.length(), l2 = str2.length();
        vector<vector<int>> lcs(l1+1, vector<int>(l2+1, 0));
        vector<pair<int, int>> track;
        for (int i = 1; i < l1+1; i++) {
        	for (int j = 1; j < l2+1; j++) {
        		int option1 = lcs[i-1][j-1] + (str1[i-1] == str2[j-1] ? 1 : 0);
        		int option2 = lcs[i-1][j];
        		int option3 = lcs[i][j-1];
                lcs[i][j] = max(option2, option3);
                if (option1 > lcs[i][j]) {
                    lcs[i][j] = option1;
                    pair<int, int> temp(i-1, j-1);
                    if (track[track.size()-1] <= temp) {
                        track.push_back(temp);
                    }
                }
        	}
        }
        
        for (int i = 0; i < track.size(); i++) {
        	cout << track[i].first << " " << track[i].second << endl;
        }

        string ans = "";
        int s1 = 0, s2 = 0;
        for (int i = 0; i < track.size(); i++) {
        	int first = track[i].first, second = track[i].second;
        	ans += str1.substr(s1, first - s1 + 1) + str2.substr(s2, second - s2);
        	s1 = first + 1;
        	s2 = second + 1;
        }
        if (s1 < l1)
            ans += str1.substr(s1, l1 - s1);
        if (s2 < l2)
            ans += str2.substr(s2, l2 - s2);
        return ans;
    }
};