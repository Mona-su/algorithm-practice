// 374. Guess Number Higher or Lower

// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I'll tell you whether the number is higher or lower.
// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int ans = low + (high - low) / 2;
        int result = guess(ans);
        while (result != 0) {
            if (result == 1) {
                low = ans + 1;
            }
            else {
                high = ans - 1;
            }
            ans = low + (high - low) / 2;
            result = guess(ans);
        }
        return ans;
    }
};