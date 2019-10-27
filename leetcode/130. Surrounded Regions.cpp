// 130 Surrounded Regions.cpp

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        
        if (row > 2) {
            int col = board[0].size();
            
            if (col > 2) {
                for (int i = 0; i < col; i++) {
                    if (board[0][i] == 'O') {
                        flipBoard (board, 0, i, 'o');
                    }
                    if (board[row-1][i] == 'O') {
                        flipBoard (board, row-1, i, 'o');
                    }
                }
                for (int i = 0; i < row; i++) {
                    if (board[i][0] == 'O') {
                        flipBoard (board, i, 0, 'o');
                    }
                    if (board[i][col-1] == 'O') {
                        flipBoard (board, i, col-1, 'o');
                    }
                }
                
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        if (board[i][j] == 'O') {
                            board[i][j] = 'X';
                        }
                        else if (board[i][j] == 'o') {
                            board[i][j] = 'O';
                        }
                    }
                }
            }
        }
    }
    
    void flipBoard (vector<vector<char>>& board, int i, int j, char ch){
        board[i][j] = ch;
        
        if (i - 1 >= 0 && board[i-1][j] == 'O') {
            flipBoard(board, i-1, j, 'o');
        }
        if (j - 1 >= 0 && board[i][j-1] == 'O') {
            flipBoard(board, i, j-1, 'o');
        }
        if (i + 1 < board.size() && board[i+1][j] == 'O') {
            flipBoard(board, i+1, j, 'o');
        }
        if (j + 1 < board[i].size() && board[i][j+1] == 'O') {
            flipBoard(board, i, j+1, 'o');
        }
    }
};