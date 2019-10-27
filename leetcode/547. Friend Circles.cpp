// 547. Friend Circles.cpp

// DFS
// space: O(1)
// time: O(c*n^2), roughly every cell is visited once, while some might be visited many times?
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int num = M.size();
        if (num == 0)	return 0;

        int id = 2;
        for (int i = 0; i < num; i++) {
        	id = dfs(M, i, id);
            // cout << "i-id: " << i << "-" << id << endl;
        }

        return id - 2;
    }

    int dfs(vector<vector<int>>& M, int row, int val) {
        for (int i = 0; i < M.size(); i++) {
            if (M[row][i] > 1){
                return val;
            }
    		if (M[row][i] == 1) {
    			M[row][i] = val;
    			dfs(M, i, val);
    		}
    	}
        // cout << "completed for loop" << endl;
        return val+1;
    }
};