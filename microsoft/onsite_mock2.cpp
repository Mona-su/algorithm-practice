// 8. String to Integer (atoi)

// Implement atoi which converts a string to an integer.
// The function first discards as many whitespace characters as necessary 
// until the first non-whitespace character is found. Then, starting from 
// this character, takes an optional initial plus or minus sign followed 
// by as many numerical digits as possible, and interprets them as a numerical 
// value.
// The string can contain additional characters after those that form the 
// integral number, which are ignored and have no effect on the behavior 
// of this function.
// If the first sequence of non-whitespace characters in str is not a valid 
// integral number, or if no such sequence exists because either str is empty 
// or it contains only whitespace characters, no conversion is performed.
// If no valid conversion could be performed, a zero value is returned.

// time O(n), space O(1)
// many many side cases to consider
class Solution {
private:
    int convert2int (string str, int sign) {
        int maxInteger;
        string maxInt;
        if (sign == -1) {
            maxInteger = INT_MIN;
            maxInt = to_string(maxInteger).substr(1);
        }
        else {
            maxInteger = INT_MAX;
            maxInt = to_string(maxInteger);
        }
        int maxLen = maxInt.length();
        int ans;
        int start = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0')
                start++;
            else
                break;
        }
        str = str.substr(start);
        if (str.length() == 0)
            return 0;
        if (str.length() > maxLen)
            return maxInteger;
        else if (str.length() == maxLen) {
            bool equal = true;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] > maxInt[i])
                    return maxInteger;
                else if (str[i] < maxInt[i]) {
                    equal = false;
                    break;
                }
            }
            if (equal)
                return maxInteger;
        }
        istringstream is(str);
        is >> ans;
        return ans*sign;
    }
public:
    int myAtoi(string str) {
        string num = "";
        int ans = 0, factor = 1;
        bool beginNum = false;
        int start = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ')
                start++;
            else
                break;
        }
        str = str.substr(start);
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '-') {
                if (!beginNum) {
                    beginNum = true;
                    factor = -1;
                }
                else
                    break;
            }
            else if (str[i] == '+') {
                if (!beginNum) {
                    beginNum = true;
                }
                else
                    break;
            }
            else if (str[i] - '0' < 10 && str[i] - '0' >= 0) {
                num += str[i];
                beginNum = true;
            }
            else {
                break;
            }
        }
        // cout << "num as string: " << num << endl;
        ans = convert2int(num, factor);
        return ans;
    }
};