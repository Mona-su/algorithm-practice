// 1144. Decrease Elements To Make Array Zigzag.cpp

// Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
// An array A is a zigzag array if either:
// Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
// OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
// Return the minimum number of moves to transform the given array nums into a zigzag array.

// time: O(n), go over the array once
// space: O(1)
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
    	int odd = 0, even = 0;
    	int len = nums.size();
    	if (len < 3)	return 0;

    	int localMin;
    	for (int i = 0; i < len; i++) {
			if (i == 0) {
				localMin = nums[i+1];
			}
			else if (i == len-1) {
				localMin = nums[i-1];
			}
			else {
				localMin = min(nums[i-1], nums[i+1]);
			}
			int move = (nums[i] < localMin) ? 0 : (nums[i] - localMin + 1);

    		if (i&1) {
    			odd += move;
    		}
    		else {
    			even += move;
    		}
    	}

    	return min(even, odd);
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().movesToMakeZigzag(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}