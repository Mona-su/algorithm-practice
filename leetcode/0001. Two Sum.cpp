// 1. Two Sum

// Given an array of integers, return indices of the two numbers such that they add up to a 
// specific target.

// You may assume that each input would have exactly one solution, and you may not use the 
// same element twice.

// brute-force, O(n^2) time, O(1) space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
};


// use hashmap, time O(nlogn), space O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        map<int, vector<int>> nums2;
        for (int i = 0; i < nums.size(); i++) {
            nums2[nums[i]].push_back(i);
        }
        for (auto itr = nums2.begin(); itr != nums2.end(); itr++) {
            auto itr2 = nums2.find(target - itr->first);
            if (itr2 != nums2.end()) {
                ans[0] = itr->second[0];
                ans[1] = itr2->second[itr2->second.size()-1];
                return ans;
            }
        }
        return ans;
    }
};

// hashmap, a bit improvement
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        unordered_map<int, int> nums2;
        for (int i = 0; i < nums.size(); i++) {
        	int diff = target - nums[i];
        	auto itr = nums2.find(diff);
        	if (itr != nums2.end()) {
        		ans[0] = i;
        		ans[1] = itr->second;
        		break;
        	}
            nums2[nums[i]] = i;
        }
        
        return ans;
    }
};