// 33 Search in Rotated Sorted Array.cpp

// O(log n) time, O(1) space
// binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1, minIndex;
        int length = nums.size();
        
        if (length > 2){
            minIndex = findMinIndex (nums, 0, length, length);
            //cout << "min index: " << minIndex << endl;
            index = doSearch (nums, target, length, minIndex, (minIndex - 1) % length);
        }
        else if (length > 0) {
            for (int i = 0; i < length; i++){
                index = (target == nums[i]) ? i : index;
            }
        }
        
        return index;
    }
    
    int doSearch (vector<int>& nums, int target, int len, int left, int right){
        int index = -1, mid, leftMid, rightMid;
        if ((right - left) % len > 1){
            if (left < right) {
            	mid = (right + left) / 2;
            }
            else {
            	mid = ((right + left + len) / 2) % len;
            }
            
            if (target == nums[mid]){
                return mid;
            }
            else if (target > nums[mid]){
                return doSearch(nums, target, len, mid + 1, right);
            }
            else {
                return doSearch(nums, target, len, left, mid);
            }
        }
        else {
        	return (nums[left] == target) ? left : -1;
        }
    }
    
    int findMinIndex (vector <int>& nums, int left, int right, int len){
        if (right - left > 2){
            int index = -1, mid, leftMid, rightMid;
            mid = ((right + left)/2)%len;
            leftMid = ((mid + left)/2)%len;
            rightMid = ((mid + 1 + right) /2)%len;
            
            if (nums[leftMid] < nums[mid] && nums[mid] < nums[rightMid]){
                return findMinIndex (nums, rightMid + 1, leftMid + len + 1, right - left);
            }
            else if (nums[mid] < nums[rightMid] && nums[rightMid] < nums[leftMid]){
                return findMinIndex (nums, leftMid + 1, mid + 1, right - left);
            }
            else if (nums[rightMid] < nums[leftMid] && nums[leftMid] < nums[mid]){
                return findMinIndex (nums, mid + 1, rightMid + 1, right - left);
            }

            return left;
        }
        else if (right - left == 1) {
            return left;
        }
        else {
            return (nums[left] > nums[left+1]) ? left+1 : left;
        }
    }
};


// 暴力解法
// O(n) time, O(1) space
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1, length = nums.size();
        if (length > 0) {
            for (int i = 0; i < length; i++){
                index = (target == nums[i]) ? i : index;
            }
        }
        
        return index;
    }
};
