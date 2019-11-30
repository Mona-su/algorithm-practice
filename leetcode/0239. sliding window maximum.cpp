class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> sol;
        
        if (length <=0 || length < k)
            return sol;
        
        // position of max element int the k elements
        int max = findMax(nums, k, 0);
        sol.push_back(nums[max]);
        for (int i = 1; i < length - k + 1; i++){
            if (max > 0){
                max--;
                if (nums[i+k-1] >= nums[max+i]){
                    max = k-1;
                    sol.push_back(nums[i+k-1]);
                }
                else {
                    sol.push_back(nums[i+max]);
                }
            }
            else{
                max = findMax(nums, k, i);
                sol.push_back(nums[i+max]);
            }
        }
        
        return sol;
    }
    
    int findMax(vector<int>& nums, int k, int index){
        int max = nums[index], maxIndex = 0;
        for (int i = 1; i < k; i++){
            if (max <= nums[index+i]){
                max = nums[index+i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};
