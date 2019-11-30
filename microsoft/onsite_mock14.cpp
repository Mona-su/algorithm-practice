// 240. Search a 2D Matrix II

// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

class Solution {
private:
    bool search(vector<vector<int>>& matrix, int row_s, int row_e, int col_s, int col_e, int target) {
        if (row_s == row_e || col_s == col_e)   return false;
        if (target < matrix[row_s][col_s] || target > matrix[row_e-1][col_e-1]) {
            return false;
        }
        else if (target == matrix[row_s][col_s] || target == matrix[row_e-1][col_e-1]) {
            return true;
        }
        else {
            int row_mid = (row_s + row_e) / 2, col_mid = (col_s + col_e) / 2;
            bool find;
            if (target > matrix[row_mid][col_mid]) {
                // travel top-right, bottom-left and bottom right
                find = search(matrix, row_s, row_mid+1, col_mid+1, col_e, target);
                if (find)   return find;
                find = search(matrix, row_mid+1, row_e, col_s, col_mid+1, target);
                if (find)   return find;
                find = search(matrix, row_mid+1, row_e, col_mid+1, col_e, target);
                return find;
                // return false;
            }
            else if (target < matrix[row_mid][col_mid]) {
                // travel top-left, bottom-left and top-right
                find = search(matrix, row_s, row_mid, col_s, col_mid, target);
                if (find)   return find;
                find = search(matrix, row_mid, row_e, col_s, col_mid, target);
                if (find)   return find;
                find = search(matrix, row_s, row_mid, col_mid, col_e, target);
                return find;
                // return false;
            }
            else {
                return true;
            }
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0)  return false;
        return search(matrix, 0, matrix.size(), 0, matrix[0].size(), target);
    }
};