/*
Given a mountain array mountainArr, return the minimum index such that 
mountainArr.get(index) == target.  If such an index doesn't exist, return -1.
You can't access the mountain array directly.  You may only access the 
array using a MountainArray interface:
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 1, e = mountainArr.length()-1;
        int peak, half_val, prev_val, post_val;
        
        while (s < e) {
            int half = (s + e) / 2;
            half_val = mountainArr.get(half);
            prev_val = mountainArr.get(half-1);
            post_val = mountainArr.get(half+1);
            if (half_val > prev_val && half_val > post_val) {
                peak = half;
                break;
            }
            else if (half_val > prev_val){
                s = half;
            }
            else {
                e = half;
            }
        }
        
        // cout << "peak: " << peak << endl;
        
        int index;
        s = 0;
        e = peak;
        half_val = mountainArr.get(s);
        if (half_val == target)
            return s;
        do {
            half_val = mountainArr.get((s+e)/2);
            if (half_val < target) 
                s = (s+e)/2;
            else if (half_val > target)
                e = (s+e)/2;
            else 
                return (s+e)/2;
        } while (s < e - 1);

        s = peak;
        e = mountainArr.length();
        half_val = mountainArr.get(s);
        if (half_val == target)
            return s;
        do {
            half_val = mountainArr.get((s+e)/2);
            if (half_val > target) 
                s = (s+e)/2;
            else if (half_val < target)
                e = (s+e)/2;
            else 
                return (s+e)/2;
        } while (s < e - 1);
        
        return -1;
    }
};