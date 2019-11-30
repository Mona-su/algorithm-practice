// 151. Reverse Words in a String

// Given an input string, reverse the string word by word.

class Solution {
private:
    vector<string> split (string s, char sep) {
        vector<string> result;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == sep) {
                if (word != "") {
                    result.push_back(word);
                    word = "";
                }
            }
            else {
                word += s[i];
            }
        }
        if (word != "")
            result.push_back(word);
        return result;
    }
public:
    string reverseWords(string s) {
        if (s.length() == 0)    return s;
        vector<string> words = split(s, ' ');
        string ans = "";
        if (words.size() == 0)  return ans;
        for (int i = words.size() - 1; i > 0; i--) {
            ans += words[i] + " ";
        }
        ans += words[0];
        return ans;
    }
};