// 299. Bulls and Cows
// need to further check answers

// You are playing the following Bulls and Cows game with your friend: You write 
// down a number and ask your friend to guess what the number is. Each time your 
// friend makes a guess, you provide a hint that indicates how many digits in said 
// guess match your secret number exactly in both digit and position (called "bulls") 
// and how many digits match the secret number but locate in the wrong position 
// (called "cows"). Your friend will use successive guesses and hints to eventually 
// derive the secret number.
// Write a function to return a hint according to the secret number and friend's guess, 
// use A to indicate the bulls and B to indicate the cows. 
// Please note that both secret number and friend's guess may contain duplicate digits.


// time: O(n)
// space: O(1)
// might be further optimized
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        int len = secret.length();
        if (secret.length() == 0)   return "0A0B";
        
        vector<int> digits(10, 0);
        for (int i = 0; i < len; i++) {
            int temp = secret[i] - '0';
            digits[temp]++;
        }
        
        for (int i = 0; i < len; i++) {
            if (guess[i] == secret[i]) {
                a++;
                int temp = secret[i] - '0';
                digits[temp]--;
            }
        }
        
        for (int i = 0; i < len; i++) {
            int temp = guess[i] - '0';
            if (guess[i] != secret[i] && digits[temp] > 0) {
                b++;
                digits[temp]--;
            }
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};