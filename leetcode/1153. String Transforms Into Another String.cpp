// 1153. String Transforms Into Another String.cpp

class Solution {
int findTypes(string str) {
	set<char> charType;
	for (int i = 0; i < str.length(); i++) {
		charType.insert(str[i]);
	}
	return charType.size();
}
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2)	return true;
        if (str1.length() != str2.length())	return false;

        int types = findTypes(str2);

        if (types == 26)	return str1 == str2;

        map<char, char> mapping;

        for (int i = 0; i < str1.length(); i++) {
        	if (mapping.find(str1[i]) == mapping.end()) {
        		mapping[str1[i]] = str2[i];
        	}
        	else {
        		if (mapping[str1[i]] != str2[i])
        			return false;
        	}
        }

        return true;
    }
};