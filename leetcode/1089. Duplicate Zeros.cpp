// 1089. Duplicate Zeros.cpp

// Given a fixed length array arr of integers, duplicate each occurrence 
// of zero, shifting the remaining elements to the right.
// Note that elements beyond the length of the original array are not written.
// Do the above modifications to the input array in place, do not return 
// anything from your function.

// use double pointer
// time: O(n)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count0 = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                count0++;
            }
        }
        int ptr1 = arr.size(), ptr2 = arr.size() + count0;
        if (ptr1 == ptr2)   return;
        while (ptr2 > 0) {
            ptr2--;
            ptr1--;
            if (ptr2 < arr.size()) {
                arr[ptr2] = arr[ptr1];
            }
            if (arr[ptr1] == 0) {
                ptr2--;
                if (ptr1 < 0 || ptr2 < 0)
                    break;
                if (ptr2 < arr.size())
                    arr[ptr2] = arr[ptr1];
            }
        }
    }
};