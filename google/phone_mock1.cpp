//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3

class MovingAverage {
private:
    int windowSize;
    int arrayLength;
    int sum;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        windowSize = size;
        arrayLength = 0;
        sum = 0;
    }
    
    double next(int val) {
        nums.push_back(val);
        sum += val;
        arrayLength++;
        if (arrayLength > 3) {
            sum -= nums[0];
            nums.erase(nums.begin());
            arrayLength--;
        }
        return sum * 1.0 / arrayLength;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */