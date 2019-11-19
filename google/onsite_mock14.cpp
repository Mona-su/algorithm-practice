// 1087. Brace Expansion

// A string S represents a list of words.
// Each letter in the word has 1 or more options.  If there is one option, 
// the letter is represented as is.  If there is more than one option, then 
// curly braces delimit the options.  For example, "{a,b,c}" represents options 
// ["a", "b", "c"].
// For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", 
//     "cde", "cdf"].
// Return all words that can be formed in this manner, in lexicographical order.


class Solution {
public:
    vector<string> expand(string S) {
        vector<string> substrings;
        string temp = "";
        int bracket = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '{') {
                if (temp.length() > 0)
                    substrings.push_back(temp);
                bracket++;
                temp = "";
            }
            else if (S[i] == '}') {
                substrings.push_back(temp);
                bracket--;
                temp = "";
            }
            else if (S[i] == ','){
                continue;
            }
            else {
                if (bracket == 0) {
                    temp += S[i];
                    substrings.push_back(temp);
                    temp = "";
                }
                else
                    temp += S[i];
            }
        }
        if (temp.length() > 0)
            substrings.push_back(temp);
        
        int total = 1;
        for (int i = 0; i < substrings.size(); i++) {
            sort(substrings[i].begin(), substrings[i].end());
            total *= substrings[i].length();
        }
        vector<string> ans(total, "");
        int consecutive, count, index, subtotal;
        subtotal = total;
        for (int i = 0; i < substrings.size(); i++) {
            subtotal /= substrings[i].length();
            count = consecutive = subtotal;
            index = 0;
            for (int j = 0; j < ans.size(); j++) {
                ans[j] += substrings[i][index%substrings[i].length()];
                count--;
                if (count == 0) {
                    index++;
                    count = consecutive;
                }
            }
        }
        
        return ans;
    }
};