// 200 Number of Islands.cpp

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        
        int col = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    //cout << "**" << i << ", " << j << endl;
                    visitNeighbor (grid, i, j);
                }
            }
        }
        
        return islandCount;
    }
    
    void visitNeighbor (vector<vector<char>>& grid, int i, int j) {
        //cout << i << ", " << j << endl;
        grid[i][j] = '2';
        int row = grid.size(), col = grid[i].size();
        
        if (i + 1 < row) {
            if (grid[i+1][j] == '1'){
                visitNeighbor (grid, i+1, j);
            }
        }
        
        if (j + 1 < col) {
            if (grid[i][j+1] == '1') {
                visitNeighbor (grid, i, j+1);
            }
        }
        
        if (j - 1 >= 0) {
            if (grid[i][j-1] == '1') {
                visitNeighbor (grid, i, j-1);
            }
        }
        
        if (i - 1 >= 0) {
            if (grid[i-1][j] == '1') {
                visitNeighbor (grid, i-1, j);
            }
        }
    }
};