// 215. Kth Largest Element in an Array.cpp

// naive approach: sort and return k-th largest
// time: O(nlogn); space: O(1) (depending on the sorting algo)

// another: median of medians
// there are runtime error currently
class Solution {
private:
	int findMiddle(vector<int>& nums) {
		if (nums.size() < 1)	return -1;
		sort(nums.begin(), nums.end());
		return nums[nums.size()/2];
	}

	// return the index of pivot in the partitioned array
	vector<int> partition(vector<int>& nums, int pivot) {
		int pivot_index = -1, pivot_occurrence = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == pivot) {
				pivot_index = i;
				break;
			}
		}
		swap(nums, nums.size()-1, pivot_index);
		pivot_index = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] >= pivot) {
				swap(nums, pivot_index, pivot_index - 1);
				swap(nums, pivot_index, i);
				pivot_index--;
				if (nums[i] == pivot) 
					pivot_occurrence++;
			}
		}
		vector<int> ans{pivot_index, pivot_index + pivot_occurrence};
		return ans;
	}

	void swap(vector<int>& nums, int i, int j) {
		int temp;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size(), ans = -1;
        if (len == 0)	return -1;
        else if (len < 2)	return nums[0];
        vector<int> medians;
        for (int i = 0; i < len; i += 5) {
    		int range = max(i + 5, len);
            vector<int> temp(nums.begin() + i, nums.begin() + range);
    		medians.push_back(findMiddle(temp));
            temp.clear();
    	}
    	int mid = findKthLargest(medians, medians.size() / 2);
    	vector<int> mid_range = partition(nums, mid);
    	if (k - 1 >= mid_range[0] && k - 1 < mid_range[1])
    		return mid;
    	else if (k - 1 >= mid_range[1]) {
    		nums.erase(nums.begin(), nums.begin() + mid_range[1]);
    		return findKthLargest(nums, k - mid_range[1] + 1);
    	}
    	else {
    		nums.erase(nums.begin() + mid_range[0], nums.end());
    		return findKthLargest(nums, k);
    	}
    }
};