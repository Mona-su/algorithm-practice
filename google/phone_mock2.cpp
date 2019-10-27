// Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
// example:
// Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
// Output: ["2", "4->49", "51->74", "76->99"]


// the tricky part of this problem:
// need to consider integer overflow and underflow, so cannot +1 or -1
// many side cases to satisfy
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        // nums.push_back(upper);
        if (nums.size() == 0) {
            ans.push_back(to_string(lower));
            if (upper > lower) {
                ans[ans.size()-1] += "->" + to_string(upper);
            }
            return ans;
        }
        
        int temp_lower = lower, temp_upper = upper;
        for (int i = 0; i < nums.size(); i++) {
            temp_upper = nums[i];
            if (temp_upper > temp_lower) {
                ans.push_back(to_string(temp_lower));
                if (temp_upper > temp_lower + 1) {
                    ans[ans.size()-1] += "->" + to_string(temp_upper-1);
                }
            }
            if (nums[i] == INT_MAX)
                break;
            temp_lower = nums[i] + 1;
        }
        
        if (upper > nums[nums.size()-1]) {
            ans.push_back(to_string(nums[nums.size()-1] + 1));
            if (upper > nums[nums.size()-1] + 1) {
                ans[ans.size()-1] += "->" + to_string(upper);
            }
        }
        
        return ans;
    }
};