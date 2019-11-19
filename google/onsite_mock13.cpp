// 1047. Remove All Adjacent Duplicates In String

// Given a string S of lowercase letters, a duplicate removal consists of 
// choosing two adjacent and equal letters, and removing them.
// We repeatedly make duplicate removals on S until we no longer can.
// Return the final string after all such duplicate removals have been made.  
// It is guaranteed the answer is unique.


class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> chars;
        chars.push(S[0]);
        for (int i = 1; i < S.length(); i++) {
            if (chars.empty()) {
                chars.push(S[i]);
                continue;
            }
            char temp = chars.top();
            if (temp != S[i]) {
                chars.push(S[i]);
            }
            else {
                chars.pop();
            }
        }
        int len = chars.size();
        int i = len - 1;
        while (!chars.empty()) {
            S[i] = chars.top();
            chars.pop();
            i--;
        }
        S.erase(len, S.length() - len);
        return S;
    }
};