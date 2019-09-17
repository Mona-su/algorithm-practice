// 1130. Minimum Cost Tree From Leaf Values.cpp

// Given an array arr of positive integers, consider all binary trees such that:
// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

// time: O(n^3)
// space: O(n^2)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
    	if (arr.size() == 0)	return 0;
  		vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 2e9));
  		vector<vector<int>> maxInSub(arr.size(), vector<int>(arr.size(), -1));

  		for (int i = 0; i < arr.size(); i++) {
  			dp[i][i] = 0;
  			maxInSub[i][i] = arr[i];
  			if (i+1 < arr.size()) {
  				dp[i][i+1] = arr[i] * arr[i+1];
  			}
  		}

  		for (int i = 0; i < arr.size(); i++) {
  			int maxN = arr[i];
  			for (int j = i + 1; j < arr.size(); j++) {
  				maxInSub[i][j] = max(maxN, arr[j]);
                maxN = max(maxN, arr[j]);
  			}
  		}

  		for (int i = 2; i < arr.size(); i++) {
  			for (int j = 0; j < arr.size(); j++) {
  				for (int k = 0; k < i; k++){
  					// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + maxInSub[i][k] * maxInSub[k+1][j]);
  					if (j + i < arr.size()){
	  					dp[j][j+i] = min(dp[j][j+i], dp[j][j+k] + dp[j+k+1][j+i] + maxInSub[j][j+k] * maxInSub[j+k+1][j+i]);
                        // cout << "dp[j][j+k]: " << dp[j][j+k] << endl;
                        // cout << "dp[j+k+1][j+i]: " << dp[j+k+1][j+i] << endl;
                        // cout << "maxInSub[j][j+k] * maxInSub[j+k+1][j+i]: " << maxInSub[j][j+k] * maxInSub[j+k+1][j+i] << endl;
                    }
  				}
  				
  			}
  		}
        
        // output for debug
        // cout << "maxInSub: " << endl;
        // for (int i = 0; i < arr.size(); i++) {
        //     for (int j = 0; j < arr.size(); j++) {
        //         cout << maxInSub[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "dp: " << endl;
        // for (int i = 0; i < arr.size(); i++) {
        //     for (int j = 0; j < arr.size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

  		return dp[0][arr.size()-1];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        
        int ret = Solution().mctFromLeafValues(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}