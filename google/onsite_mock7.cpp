// 852. Peak Index in a Mountain Array

// Let's call an array A a mountain if the following properties hold:
// A.length >= 3
// There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... 
// A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
// Given an array that is definitely a mountain, return any i such that 
// A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

// naive, O(n) time
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i+1])
                return i;
        }
        return -1;
    }
};


// binary, O(logn)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int s = 1, e = A.size() - 1;
        while (s < e) {
            int half = (s+e)/2;
            if (A[half] > A[half-1] && A[half] > A[half+1]) {
                return half;
            }
            else if (A[half] > A[half-1]){
                s = half;
            }
            else {
                e = half;
            }
        }
        return -1;
    }
};