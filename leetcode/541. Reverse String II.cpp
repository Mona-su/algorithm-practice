// 541. Reverse String II

class Solution {
private:
    void reverse (string& s, int start, int end) {
        int len = end - start;
        // cout << "start: " << start << endl;
        // cout << "end: " << end << endl;
        for (int i = 0; i < len/2; i++) {
            char temp = s[end-i-1];
            s[end-i-1] = s[start+i];
            s[start+i] = temp;
        }
        // cout << "*" << s << endl;
    }
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        int start = 0;
        while (start < len) {
            int reverse_end = min(start + k, len);
            reverse (s, start, reverse_end);
            start += 2*k;
        }
        return s;
    }
};