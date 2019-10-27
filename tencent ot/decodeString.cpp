// decodeString.cpp

#include <iostream>
#include <sstream>

using namespace std;

string decodeString (string s);

int main(){
    string encoded;
    cin >> encoded;
    
    string decoded = decodeString(encoded);
    
    cout << decoded << endl;
    return 0;
}

// // HG[3|B[2|CA]]F
// string decodeString (string s, int start, int end) {
//     int repeatI, countBracket = 0, st, e;
//     string ans = "", tempS = "", repeatS = "";
    
//     int i = start;
//     while (i < end) {
//         cout << i << endl;
//         if (s[i] == '[') {
//             countBracket++;
//             if (countBracket == 1) {
//                 i++;
//                 repeatS = "";
//                 while (s[i] >= '0' && s[i] <= '9') {
//                     repeatS += s[i];
//                     i++;
//                 }
//                 st = i + 1;
//                 istringstream is(repeatS);
//                 is >> repeatI;
//                 cout << "st: " << st << endl;
//                 cout << "repeatI: " << repeatI << endl;
//             }
//         }
//         else if (s[i] == ']') {
//             countBracket--;
//             if (countBracket == 0) {
//                 e = i;
//                 tempS = decodeString(s, st, e);
//                 for (int j = 0; j < repeatI; j++) {
//                     ans += tempS;
//                 }
//                 cout << "e: " << e << endl;
//                 cout << "repeatI: " << repeatI << endl;
//                 cout << "tempS: " << tempS << endl;
//             }
//         }
//         // else if (s[i] == '|') {
//         //     istringstream is(repeatS);
//         //     is >> repeatI;
//         //     repeatS = "";
//         //     cout << "repeatI: " << repeatI << endl;
//         // }
//         // else if (s[i] >= '0' && s[i] <= '9') {
//         //     repeatS += s[i];
//         // }
//         else {
//             if (countBracket == 0) {
//                 ans += s[i];
//             }
//         }
//         i++;
//     }

//     return ans;
// }


string decodeString (string s) {
    string ans = "";
    string repeatStr = "", temp = "";
    int repeatInt, length = s.length(), bracket = 0;

    int i = 0;
    while (i < length) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (bracket == 0) {
                ans += s[i];
            }
        }
        else {
            if (s[i] == '[' && bracket == 0) {
                bracket ++;
                i++;
                repeatStr = "";
                while (s[i] >= '0' && s[i] <= '9') {
                    repeatStr += s[i];
                    i++;
                }
                istringstream is(repeatStr);
                is >> repeatInt;
                i++;
                temp = "";
                while (bracket > 0) {
                    if (s[i] == ']') {
                        bracket--;
                    }
                    temp += s[i];
                    i++;
                }
                temp.erase (temp.length() - 1);
                temp = decodeString (temp);
                for (int j = 0; j < repeatInt; j++) {
                    ans += temp;
                }
            }
        }
        i++;
    }
    return ans;
}