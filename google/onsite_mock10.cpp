// 205. Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while 
// preserving the order of characters. No two characters may map to the same 
// character but a character may map to itself.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mappings; // unordered map and set might be a bit faster
        unordered_set<char> mapped;
        int lens = s.length(), lent = t.length();
        if (lens != lent) return false;
        if (lens == 0)  return true;
        
        for (int i = 0; i < lens; i++) {
            if (mappings.count(s[i]) > 0) {
                if (mappings[s[i]] != t[i])
                    return false;
            }
            else {
                if (mapped.count(t[i]) > 0)
                    return false;
                else {
                    mappings[s[i]] = t[i];
                    mapped.insert(t[i]);
                }
            }
        }
        return true;
    }
};