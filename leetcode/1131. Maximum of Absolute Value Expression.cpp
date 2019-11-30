// 1131. Maximum of Absolute Value Expression

// Given two arrays of integers with equal lengths, return the maximum value of:
// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
// where the maximum is taken over all 0 <= i, j < arr1.length.

// brute-force, time O(n^2), space O(1)
// time limit exceed
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int Max = 0;
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = i; j < arr1.size(); j++) {
                Max = max(Max, abs(arr1[i]-arr1[j]) + abs(arr2[i]-arr2[j]) + abs(i-j));
            }
        }
        return Max;
    }
};