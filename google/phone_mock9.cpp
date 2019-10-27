// To some string S, we will perform some replacement operations that replace 
// groups of letters with new ones (not necessarily the same size).
// Each replacement operation has 3 parameters: a starting index i, a source 
// word x and a target word y.  The rule is that if x starts at position i in 
// the original string S, then we will replace that occurrence of x with y.  
// If not, we do nothing.
// For example, if we have S = "abcd" and we have some replacement operation 
// i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the 
// original string S, we will replace it with "ffff".

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans = S;
        int diff = 0;
        vector<int> pos(S.length(), -1);
        for (int i = 0; i < indexes.size(); i++) {
            if (indexes[i] >= S.length())
                continue;
            pos[indexes[i]] = i;
        }
        cout << "debug" << endl;
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] != -1) {
                if (S.substr(indexes[pos[i]], sources[pos[i]].length()) == sources[pos[i]]) {
                    // int ans_pos = ans.find(sources[i]);
                    ans = ans.substr(0, indexes[pos[i]] + diff) + targets[pos[i]] + ans.substr(indexes[pos[i]] + diff + sources[pos[i]].length());
                    diff += targets[pos[i]].length() - sources[pos[i]].length();
                }
            }
            
        }
        
        return ans;
    }
};