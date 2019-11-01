// 399. Evaluate Division
// need to further check answers

// Equations are given in the format A / B = k, where A and B are variables 
// represented as strings, and k is a real number (floating point number). 
// Given some queries, return the answers. If the answer does not exist, return -1.0.

// many side cases to consider
// time: O(eloge + qlogq) // need further clarification
// space: O(e)
class Solution {
private:
    bool valid = true;
    set<string> nodes;
    
    double evaluate_query (map<string, string>& sides, map<string, double>& values, vector<string>& query) {
        if (query[0] == query[1]) {
            if (nodes.count(query[0]) == 0){
                valid = false;
                return -1;
            }
            return 1;
        }
        
        auto itrs = sides.find(query[0]);
        auto itrv = values.find(query[0]);
        if (itrs != sides.end() && valid) {
            query[0] = itrs->second;
            // cout << "##" << itrv->second << endl;
            return (itrv->second)*evaluate_query(sides, values, query);
        }
        else if ((itrs = sides.find(query[1])) != sides.end() && valid){
            itrv = values.find(query[1]);
            query[1] = itrs->second;
            // cout << "**" << itrv->second << endl;
            return 1.0 / (itrv->second) * evaluate_query(sides, values, query);
        }
        else {
            valid = false;
            return -1;
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        if (queries.size() == 0 || equations.size() == 0)
            return vector<double>();
        
        int q = queries.size(), e = equations.size();
        map<string, string> equation_side;
        map<string, double> equation_value;
        
        for (int i = 0; i < e; i++) {
            nodes.insert(equations[i][0]);
            nodes.insert(equations[i][1]);
            if (equation_side.count(equations[i][0]) > 0) {
                if (equation_side.count(equations[i][1]) == 0) {
                    equation_side[equations[i][1]] = equations[i][0];
                    equation_value[equations[i][1]] = 1 / values[i];
                }
            }
            else {
                equation_side[equations[i][0]] = equations[i][1];
                equation_value[equations[i][0]] = values[i];
            }
        }
        
        vector<double> ans;
        for (int i = 0; i < q; i++) {
            valid = true;
            double temp = evaluate_query(equation_side, equation_value, queries[i]);
            if (!valid)
                ans.push_back(-1);
            else
                ans.push_back(temp);
        }
        
        return ans;
    }
};