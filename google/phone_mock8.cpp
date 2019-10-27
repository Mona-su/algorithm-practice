// Given a non-empty array of digits representing a non-negative integer, plus 
// one to the integer.
// The digits are stored such that the most significant digit is at the head of 
// the list, and each element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the 
// number 0 itself.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool finished = false;
        for (int i = digits.size() - 1; i >= 0 && !finished; i--) {
            if (digits[i] + 1 < 10) {
                finished = true;
                // cout << "finish value changed" << endl;
                // cout << "digits[i] + 1 = " << digits[i] + 1 << endl;
            }
            digits[i] = (digits[i] + 1) % 10;
        }
        if (!finished) {
            digits.insert(digits.begin(), 1);
            // cout << "inserted" << endl;
        }
        return digits;
    }
};