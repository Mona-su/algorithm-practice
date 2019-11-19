// 128. Longest Consecutive Sequence.cpp
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.
*/

// #include <hash_map>
// when including hash_map: backward_warning.h:32:2: warning: 
// #warning This file includes at least one deprecated or 
// antiquated header which may be removed without further notice at a future date.

// BFS
// time: O(nlogn) as map (红黑树实现) use O(n) to find an element with specific key
// space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)	return nums.size();

        map<int, int> nodes;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
        	// nums[i] not in nodes
        	if (nodes.find(nums[i]) == nodes.end()) {
        		int left = (nodes.find(nums[i]-1) == nodes.end()) ? 0 : nodes[nums[i]-1];
        		int right = (nodes.find(nums[i]+1) == nodes.end()) ? 0 : nodes[nums[i]+1];

        		int temp = left + right + 1;
        		nodes[nums[i]] = temp;
        		nodes[nums[i]-left] = temp;
        		nodes[nums[i]+right] = temp;

        		if (temp > ans)
        			ans = temp;
        	}
        }
        return ans;
    }

};


// union find + BFS
// time: O(nlogn)
// space: O(n)
// not any better than simply using BFS, just a practice for union find
class Solution {
private: 
	vector<int> parents;
	void init (vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			parents.push_back(i);
		}
	}

	// argument: tar is the index of target value
	// return the index of root
	int find (int tar) {
		while (tar != parents[tar]) {
			parents[tar] = parents[parents[tar]];
			tar = parents[tar];
		}
		return tar;
	}

	// given p and q, check whether they are in the same tree
	// union the two if not
	void unionTwo (int p, int q) {
		int proot = find(p);
		int qroot = find(q);
		if (proot != qroot) {
			parents[proot] = qroot;
		}
	}

	int findLongest () {
		vector<int> count(parents.size(), 0);
		int max = 0;
		for (int i = 0; i < parents.size(); i++) {
			int root = find(parents[i]);
			count[root]++;
			max = (max < count[root]) ? count[root] : max;
		}
		
		return max;
	}

public:
    int longestConsecutive(vector<int>& nums) {
    	if (nums.size() < 2)	return nums.size();

        init(nums);
        map<int, int> nodes;

        for (int i = 0; i < nums.size(); i++) {
        	if (nodes.find(nums[i]) == nodes.end()) {
        		nodes[nums[i]] = i;
        		if (nodes.find(nums[i]-1) != nodes.end()) {
        			unionTwo(i, nodes[nums[i]-1]);
        		}
        		if (nodes.find(nums[i]+1) != nodes.end()) {
        			unionTwo (i, nodes[nums[i]+1]);
        		}
        	}
        }

        return findLongest();
    }

};