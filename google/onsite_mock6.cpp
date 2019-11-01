// 857. Minimum Cost to Hire K Workers

// There are N workers.  The i-th worker has a quality[i] and a minimum wage 
// expectation wage[i].
// Now we want to hire exactly K workers to form a paid group.  When hiring 
// a group of K workers, we must pay them according to the following rules:
// Every worker in the paid group should be paid in the ratio of their quality 
// compared to other workers in the paid group.
// Every worker in the paid group must be paid at least their minimum wage 
// expectation.
// Return the least amount of money needed to form a paid group satisfying 
// the above conditions.

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int len = quality.size();
        vector<double> wage2quality(len);
        for (int i = 0; i < len; i++) {
            wage2quality[i] = wage[i] * 1.0 / quality[i];
        }
        
        double ans = 0, maxWage = -1e9;
        int sum = 0;
        priority_queue<int> kquality;
        
        for (int i = 0; i < K; i++) {
            kquality.push(quality[i]);
            sum += quality[i];
            maxWage = max(maxWage, wage2quality[i]);
        }
        
        ans = maxWage * sum;
        
        for (int i = K; i < len; i++) {
            double tempMaxWage = max(maxWage, wage2quality[i]);
            int tempSum = 
        }
        
        return ans;
    }
};