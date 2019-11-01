// 766. Toeplitz Matrix

// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same 
// element.
// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
// Follow up:
// What if the matrix is stored on disk, and the memory is limited such that you can only 
// load at most one row of the matrix into the memory at once?
// What if the matrix is so large that you can only load up a partial row into the memory 
// at once?

// this would also solve the follow up questions if there is small extra space in memory 
// allowing just one entry
// time: O(m*n)
// space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};