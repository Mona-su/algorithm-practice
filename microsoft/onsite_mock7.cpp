// Design a Tic-tac-toe game that is played between two players on a n x n grid. 
// You may assume the following rules: 
// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves is allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, 
// or diagonal row wins the game.

class TicTacToe {
private:
    vector<vector<int>> board;
    int size;
    
    bool checkRow(int row, int col, int player) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] != player)
                return false;
        }
        return true;
    }
    
    bool checkCol(int row, int col, int player) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] != player)
                return false;
        }
        return true;
    }
    
    bool checkDiag(int row, int col, int player) {
        if (row != col && row != size-1-col) return false;
        bool win1 = true, win2 = true;
        for (int i = 0; i < size; i++) {
            if (board[i][i] != player) 
                win1 = false;
            if (board[i][size-1-i] != player)
                win2 = false;
            if ((!win1) && (!win2))
                return false;
        }
        return true;
    }
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        // initialize board
        vector<vector<int>> temp(n, vector<int>(n, 0));
        board = temp;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        if (checkRow(row, col, player) || checkCol(row, col, player) || checkDiag(row, col, player)) 
            return player;
        else
            return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */