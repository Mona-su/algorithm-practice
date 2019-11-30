// Given an integer array nums, find the contiguous subarray 
// (containing at least one number) which has the largest sum 
// and return its sum.

// time: O(n), space: O(1)
// the idea of dp, but no need to record every result
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        
        int curr_max = nums[0], Max = curr_max;
        
        for (int i = 1; i < nums.size(); i++) {
            curr_max = max(curr_max + nums[i], nums[i]);
            Max = max(Max, curr_max);
        }
        return Max;
    }
};

// divide and conquer
// time: O(nlogn), 
// space O(1) (if don't take into consideration the stack for recursion)
class Solution {
private:
    int maxSub (vector<int>& nums, int start, int end) {
        if (end - start == 1) {
            return nums[start];
        }
        
        int half = (start + end) / 2;
        int left = maxSub(nums, start, half);
        int right = maxSub(nums, half, end);
        int middle = 0, curr = 0, count = 0;
        for (int i = half-1; i >= start; i--) {
            curr = curr + nums[i];
            if (curr > middle) {
                middle = curr;
                count = 1;
            }
        }
        curr = middle;
        for (int i = half; i < end; i++) {
            curr += nums[i];
            if (curr > middle) {
                middle = curr;
                count = 1;
            }
        }
        if (count == 0)
            middle = max(nums[half], nums[half-1]);
        return max(middle, max(left, right));
    }
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)   return 0;
        return maxSub(nums, 0, nums.size());
    }
};

