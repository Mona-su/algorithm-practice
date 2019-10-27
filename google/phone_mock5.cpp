// 1007. Minimum Domino Rotations For Equal Row

// In a row of dominoes, A[i] and B[i] represent the top and bottom 
// halves of the i-th domino.  (A domino is a tile with two numbers 
// from 1 to 6 - one on each half of the tile.)
// We may rotate the i-th domino, so that A[i] and B[i] swap values.
// Return the minimum number of rotations so that all the values in 
// A are the same, or all the values in B are the same.
// If it cannot be done, return -1.

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> tilesA(6, 0), tilesB(6, 0), tilesBoth(6, 0);
        int ans = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) 
                tilesBoth[A[i]-1]++;
            else {
                tilesA[A[i]-1]++;
                tilesB[B[i]-1]++;
            }
        }
        int num = -1;
        for (int i = 0; i < 6; i++) {
            if (tilesA[i] + tilesB[i] + tilesBoth[i] >= A.size()) {
                num = max(num, max(tilesA[i], tilesB[i]) + tilesBoth[i]);
            }
        }
        if (num != -1) {
            ans = A.size() - num;
        }
        return ans;
    }
};