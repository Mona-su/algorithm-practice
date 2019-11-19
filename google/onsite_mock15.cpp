// 1032. Stream of Characters

// Implement the StreamChecker class as follows:
// StreamChecker(words): Constructor, init the data structure with the given words.
// query(letter): returns true if and only if for some k >= 1, the last k characters 
// queried (in order from oldest to newest, including this letter just queried) spell 
// one of the words in the given list.

// time limit exceed
class StreamChecker {
private:
    vector<set<string>> all_words = vector<set<string>>(2000);
    vector<char> buffer;
    int index, querySize, bufferLen;
public:
    StreamChecker(vector<string>& words) {
        int Max = 0;
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].length();
            all_words[len-1].insert(words[i]);
            Max = max(Max, len);
        }
        bufferLen = Max;
        buffer = vector<char>(Max);
        querySize = index = 0;
    }
    
    bool query(char letter) {
        buffer[index] = letter;
        querySize++;
        index = (index + 1) % bufferLen;
        for (int i = 0; i < 2000; i++) {
            if (all_words[i].size() == 0)
                continue;
            if (i >= querySize)
                break;
            string temp = "";
            int count = i;
            int start = (index-i-1+bufferLen)%bufferLen;
            if (start > index - 1) {
                temp.append(buffer.begin()+start, buffer.end());
                temp.append(buffer.begin(), buffer.begin()+index);
            }
            else {
                temp.append(buffer.begin()+start, buffer.begin()+index);
            }
            // while (count >= 0) {
            //     temp += buffer[(index-count-1+bufferLen)%bufferLen];
            //     count--;
            // }
            if (all_words[i].count(temp) > 0)
                return true;
            // for (int j = 0; j < all_words[i].size(); j++) {
            //     if (temp == all_words[i][j])
            //         return true;
            // }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */