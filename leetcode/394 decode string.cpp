// with assumption: the original data does not contain any digits 
// and digits are only for those repeat numbers, k. 
// For example, there won't be input like 3a or 2[4].
// time: O(n) 62.85%, space： O(1) 52.27%
class Solution {
public:
    string decodeString(string s) {
        string out = "";
        string repeatStr = "", temp = "";
        int repeatInt, length = s.length(), bracket = 0;
        
        int i = 0;
        while (i < length - 1){
            // cout << i << endl;
            if (s[i] >= '0' && s[i] <= '9'){
                repeatStr += s[i];
                if (s[i+1] == '['){
                    bracket++;
                    temp = "";
                    istringstream is(repeatStr);
                    is >> repeatInt;
                    repeatStr = "";
                    i = i + 2;
                    while (bracket > 0){
                        temp += s[i];
                        i++;
                        if (s[i] == '['){
                            bracket++;
                        }
                        else if (s[i] == ']'){
                            bracket--;
                        }
                    }
                    temp = decodeString (temp);
                    for (int j = 0; j < repeatInt; j++){
                        out += temp;
                    }
                }
                // without the assumption, just add the following code
                // because if the char after digit is a - z, the digit is not for repeating
                // else if (s[i+1] >= 'a' && s[i+1] <= 'z'){
                //     out += repeatStr;
                // }
            }
            else {
                out += s[i];
            }
            i++;
        }
        
        if (s[length-1] != ']'){
            out += s[length-1];
        }
        
        return out;
    }

};