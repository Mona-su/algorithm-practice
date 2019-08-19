#include <iostream>
#include <set>
#include <vector>

using namespace std;

int checkEvenBits (int input);
int maxSubinterval (set<int>& oddIndex, int len);
void updateSet (set<int>& oddIndex, int pi);

int main(){
    int T, Case = 1;
    cin >> T;
    while (Case <= T) {
        int n, q;
        int temp, pi, vi;
        cin >> n >> q;
        if (n == 0 || q == 0) {
            for (int i = 0; i < n + 2*q; i++) 
                cin >> temp;
            cout << "Case #" << Case << ":";
            Case++;
            continue;
        }
        
        vector<int> nums(n), results(q);
        set<int> oddIndex;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            nums[i] = checkEvenBits(temp);
            if (!nums[i]){
                oddIndex.insert(i);
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> pi >> vi;
            vi = checkEvenBits(vi);
            // if (!(nums[pi]&1)) {
            //     oddIndex.erase(oddIndex.find(pi));
            // }
            // nums[pi] = vi;
            // if (!(vi&1)) {
            //     oddIndex.insert(pi);
            // }
            // results[i] = maxSubinterval (oddIndex, nums.size());
            if (i == 0) {
                if (vi != nums[pi])
                    updateSet(oddIndex, pi);
                nums[pi] = vi;
                results[i] = maxSubinterval (oddIndex, nums.size());
                continue;
            }
            if (vi != nums[pi]) {
                nums[pi] = vi;
                updateSet(oddIndex, pi);
                results[i] = maxSubinterval (oddIndex, nums.size());
                continue;
            }
            
            results[i] = results[i-1];
            
        }

        printf("Case #%d:", Case);
        for (int i = 0; i < results.size(); i++) {
            printf(" %d", results[i]);
        }
        printf("\n");
        Case++;
    }

    return 0;
}

void updateSet (set<int>& oddIndex, int pi) {
    if (oddIndex.find(pi) != oddIndex.end()) {
        oddIndex.erase(oddIndex.find(pi));
    }
    else {
        oddIndex.insert(pi);
    }
}

// return 0 if odd bits, 1 otherwise
int checkEvenBits (int input){
    int count = 0;
    // cout << input;
    for (int i = 0; i < 10; i++){
        if (input&1){
            count++;
        }
        input = input >> 1;
    }

    // cout << "-" << !(count&1) << endl;

    return !(count&1);
}

int maxSubinterval (set<int>& oddIndex, int len) {
    if (oddIndex.size()&1) {
        int left = *(oddIndex.begin());
        int right = *(oddIndex.rbegin());
        int deleted = min(left + 1, len - right);
        // cout << "set content: ";
        // for (set<int>::iterator itr = oddIndex.begin(); itr != oddIndex.end(); itr++) {
        //     cout << *(itr) << " ";
        // }
        // cout << endl << "len - deleted: " << len - deleted << endl;
        return len - deleted;
    }
    // cout << "len: " << len << endl;
    return len;
}