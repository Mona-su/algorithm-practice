class Solution {
private:
    int lastOnePali(unordered_set<int>& pos, string s, int index, int lastone) {
        int ans = 0;
        unordered_set<int> newset;
        if (s[index] == s[index-1]) {
            ans++;
            newset.insert(index-1);
        }
        for (auto elem : pos) {
            if (elem == 0)
                continue;
            if (s[index] == s[elem-1]) {
                ans++;
                newset.insert(elem-1);
            }
        }
        pos = newset;
        return ans;
    }
public:
    int countSubstrings(string s) {
        if (s.length() < 2) return s.length();
        
        int last = 1, curr, lastone = 1;
        unordered_set<int> beginnings;
        beginnings.insert(0);
        for (int i = 1; i < s.length(); i++) {
            curr = last + 1 + lastOnePali(beginnings, s, i, lastone);
            last = curr;
        }
        return curr;
    }
};