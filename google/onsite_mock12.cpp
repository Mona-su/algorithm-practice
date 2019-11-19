// 394. Decode String

// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square 
// brackets is being repeated exactly k times. Note that k is guaranteed to be a positive 
// integer.
// You may assume that the input string is always valid; No extra white spaces, square 
// brackets are well-formed, etc.
// Furthermore, you may assume that the original data does not contain any digits and 
// that digits are only for those repeat numbers, k. For example, there won't be input 
// like 3a or 2[4].

// use recursion
class Solution {
public:
    string decodeString(string s) {
        string ans = "", repeat_s = "", temp;
        int bracket = 0, repeat, start;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                bracket++;
                if (bracket == 1) {
                    start = i+1;
                }
                continue;
            }
            else if (s[i] == ']') {
                bracket--;
                if (bracket == 0) {
                    temp = decodeString(s.substr(start, i - start));
                    istringstream is(repeat_s);
                    is >> repeat;
                    for (int j = 0; j < repeat; j++) {
                        ans += temp;
                    }
                    repeat_s = "";
                }
                continue;
            }
            if (bracket == 0) {
                if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                    repeat_s += s[i];
                }
                else {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};

// use iteration
class Solution {
public:
    string decodeString(string s) {
        string ans = "", repeat_s = "", curr;
        int bracket = 0, start;
        stack<int> repeat;
        stack<string> pattern;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                bracket++;
                istringstream is(repeat_s);
                int temp;
                is >> temp;
                repeat.push(temp);
                repeat_s = "";
                pattern.push(curr);
                curr = "";
            }
            else if (s[i] == ']') {
                bracket--;
                int temp = repeat.top();
                repeat.pop();
                pattern.push(curr);
                string temps = pattern.top();
                pattern.pop();
                curr = pattern.top();
                for (int j = 0; j < temp; j++) {
                    curr += temps;
                }
                pattern.pop();
            }
            else if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                repeat_s += s[i];
            }
            else {
                curr += s[i];
            }
        }

        return pattern.top();
    }
};