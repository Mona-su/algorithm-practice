// 27. remove element.cpp

// with self-designed removeOne, the performance better
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();

        for (int i = 0; i < len; i++) {
        	if (nums[i] == val) {
        		removeOne(nums, i, len);
        		// nums.erase(nums.begin() + i);
        		len--; 
        		i--;
        	}
        }

        return len;
    }

    void removeOne (vector<int>& nums, int index, int len) {
    	int temp = nums[index];
    	nums[index] = nums[len-1];
    	nums[len-1] = temp; 
    }
};