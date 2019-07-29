class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pointers[2] = {-1, -1};
        if (nums.size() > 1){
            if (nums[0] > 0){
                pointers[nums[0] - 1] = 0;
            }
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] == 1){
                    if (pointers[1] > -1){
                        swap(nums, i, pointers[1]);
                        pointers[0] = (pointers[0] < 0) ? pointers[1] : pointers[0];
                        pointers[1]++;
                    }
                    else {
                        pointers[0] = (pointers[0] < 0) ? i : pointers[0];
                    }
                }
                else if (nums[i] == 0){
                    if (pointers[0] > -1){
                        swap (nums, i, pointers[0]);
                        pointers[0]++;
                        if (pointers[1] > -1){
                            swap (nums, i, pointers[1]);
                            pointers[1]++;
                        }
                    }
                    else{
                        if (pointers[1] > -1){
                            swap (nums, i, pointers[1]);
                            pointers[1]++;
                        }
                    }
                }
                else{
                    pointers[1] = (pointers[1] < 0) ? i : pointers[1];
                }
            }
        }
    }
    
    void swap (vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
