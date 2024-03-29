// Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, 
// there may exist one celebrity. The definition of a celebrity is that all the other 
// n - 1 people know him/her but he/she does not know any of them.
// Now you want to find out who the celebrity is or verify that there is not one. The 
// only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" 
// to get information of whether A knows B. You need to find out the celebrity (or 
//     verify there is not one) by asking as few questions as possible (in the asymptotic 
//     sense).
// You are given a helper function bool knows(a, b) which tells you whether A knows B. 
// Implement a function int findCelebrity(n). There will be exactly one celebrity if 
// he/she is in the party. Return the celebrity's label if there is a celebrity in the 
// party. If there is no celebrity, return -1.


// Forward declaration of the knows API.
bool knows(int a, int b);

// time: approximately O(n), space: O(n)
class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> celebrities;
        for (int i = 0; i < n; i++)
            celebrities.insert(i);
        
        while (!celebrities.empty()) {
            int possible = *celebrities.begin();
            // cout << possible << endl;
            bool findPossible = true;
            for (int i = 0; i < n; i++) {
                if (i == possible)
                    continue;
                if (knows(i, possible)) {
                    if (celebrities.count(i) > 0)
                        celebrities.erase(i);
                }
                else {
                    // cout << i << " " << possible << endl;
                    findPossible = false;
                    break;
                }
            }
            if (findPossible) {
                for (int i = 0; i < n; i++) {
                    if (i == possible)
                        continue;
                    if (knows(possible, i)) {
                        return -1;
                    }
                }
                return possible;
            }
            else {
                celebrities.erase(possible);
            }
        }
        
        return -1;
    }
};