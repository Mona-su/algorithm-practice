// leetcode 616. Add Bold Tag in String

// Given a string s and a list of strings dict, you need to add a closed 
// pair of bold tag <b> and </b> to wrap the substrings in s that exist 
// in dict. If two such substrings overlap, you need to wrap them together 
// by only one pair of closed bold tag. Also, if two substrings wrapped by 
// bold tags are consecutive, you need to combine them. 

class Solution {
private:
    struct pair{
        int left, right;
    };
    static bool compare (pair a, pair b) {
        if (a.left < b.left)
            return true;
        else if (a.left == b.left) {
            return a.right > b.right;
        }
        return false;
    }
public:
    string addBoldTag(string s, vector<string>& dict) {
        string ans = "";
        vector<pair> substrPos;
        for (int i = 0; i < dict.size(); i++) {
            size_t found = s.find(dict[i]);
            while (found != string::npos) {
                pair temp = {static_cast<int>(found), static_cast<int>(found) + dict[i].length()};
                substrPos.push_back(temp);
                found = s.find(dict[i], found + 1);
            }
        }
        if (substrPos.size() == 0) {
            return s;
        }
        sort(substrPos.begin(), substrPos.end(), compare);
        int len = substrPos.size();
        int start = substrPos[0].left, end = substrPos[0].right;
        // cout << "after sort" << endl;
        // for (int i = 0; i < len; i++) {
        //     cout << "position: " << substrPos[i].left << "-" << substrPos[i].right << endl;
        // }
        for (int i = 1; i < len; i++) {
            if (substrPos[i].left <= end) {
                end = max(substrPos[i].right, end);
            }
            else {
                pair temp = {start, end};
                substrPos.push_back(temp);
                start = substrPos[i].left;
                end = substrPos[i].right;
            }
        }
        pair temp = {start, end};
        substrPos.push_back(temp);
        substrPos.erase(substrPos.begin(), substrPos.begin() + len);
        // cout << "after merge" << endl;
        // for (int i = 0; i < substrPos.size(); i++) {
        //     cout << "position: " << substrPos[i].left << "-" << substrPos[i].right << endl;
        // }
        
        start = substrPos[0].left;
        end = 0;
        for (int i = 0; i < substrPos.size(); i++) {
            start = substrPos[i].left;
            ans += s.substr(end, start - end);
            end = substrPos[i].right;
            ans += "<b>" + s.substr(start, end - start) + "</b>";
        }
        ans += s.substr(end, s.length() - end);
        
        return ans;
    }
};