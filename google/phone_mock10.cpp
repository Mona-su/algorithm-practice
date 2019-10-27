// Given a collection of intervals, merge all overlapping intervals.

class Solution {
private:
    static bool compare (vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() == 0)  return ans;
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > intervals[i][1])
                continue;
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                vector<int> pair{start, end};
                ans.push_back(pair);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> pair{start, end};
        ans.push_back(pair);
        return ans;
    }
};