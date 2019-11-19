// 1032. Stream of Characters

// Implement the StreamChecker class as follows:
// StreamChecker(words): Constructor, init the data structure with the given words.
// query(letter): returns true if and only if for some k >= 1, the last k characters 
// queried (in order from oldest to newest, including this letter just queried) spell 
// one of the words in the given list.

// time limit exceed
class StreamChecker {
private:
    struct TreeNode
    {
        // char val;
        bool word; // if this from root to this node forms a word, true
        TreeNode children[26];
    };
    TreeNode* root;
    vector<char> buffer;
    int index, querySize, bufferLen;
public:
    StreamChecker(vector<string>& words) {
        int Max = 0;
        for (int i = 0; i < 26; i++)
            root->children[i] = NULL;
        TreeNode *temp;
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].length();
            Max = max(Max, len);
            temp = root;
            int j;
            for (j = len-1; j >= 0; j--) {
                if (temp->children[words[i][j]-'a'] == NULL) {
                    break;
                }
                else {
                    temp = temp->children[words[i][j]-'a'];
                }
            }
            for (; j >= 0; j--) {
                TreeNode *curr;
                // curr->val = words[i][j];
                curr->word = false;
                for (int k = 0; k < 26; k++)
                    curr->children[i] = NULL;
                temp->children[words[i][j]-'a'] = curr;
                temp = curr;
            }
            temp->word = true;
        }
        bufferLen = Max;
        buffer = vector<char>(Max);
        querySize = index = 0;
    }
    
    bool query(char letter) {
        buffer[index] = letter;
        querySize++;
        index = (index + 1) % bufferLen;
        // string temp = "";
        // int start = (index - 1 + bufferLen) % bufferLen;
        TreeNode *curr = root;
        for (int i = 0; i < bufferLen && i < querySize; i++) {
            char temp = buffer[(index - 1 - i + bufferLen) % bufferLen];
            if (curr->children[temp-'a'] != NULL) {
                curr = children[temp-'a'];
                if (curr->word)
                    return true;
            }
            else {
                return false;
            }
        }
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */