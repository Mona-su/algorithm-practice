// 169 Majority Element.cpp

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int pivot = nums[0], count = 0;
        
        for (int i = 1; i < len; i++) {
            count = (pivot == nums[i]) ? count+1 : count-1;
            if (count < 0) {
                count = 0;
                pivot = nums[i];
            }
        }
        
        return pivot;
    }
};