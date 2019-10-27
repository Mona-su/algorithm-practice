#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Case{
    int N, G, M;
    vector<int> guestsAtH;
    vector<char> guestsType;
    vector<vector<int>> result;
};

Case readCase();

int main(){
    int numOfCase;
    string dummy;
    cin >> numOfCase;
    Case cases[numOfCase];
    getline(cin, dummy);

    // read inputs
    if (numOfCase > 0){
        for (int i = 0; i < numOfCase; i++) {
            cases[i] = readCase();
        }

        for (int i = 0; i < numOfCase; i++){
            cout << "Case #" << i+1 << ":";
            if (cases[i].N > 0 && cases[i].G > 0){
                for (int j = 0; j < cases[i].N; j++){

                }
            }
            cout << endl;
        }
    }

    return 0;
}

Case readCase(){
    string dummy;
    Case out;

    cin >> out.N >> out.G >> out.M;
    getline(cin, dummy);

    if (out.G > 0){
        for (int i = 0; i < out.G; i++){
            int h;
            char type;
            cin >> h >> type;
            getline(cin, dummy);
            out.guestsAtH.push_back(h);
            out.guestsType.push_back(h);
        }
    }

    return out;
}

void findSolution (Case input){
    for (int i = 0; i < input.G; i++){
        vector<int> temp;
        temp.push_back(input.guestsAtH[i]);
        for (int j = 1; j < input.M + 1; j++){
            temp.push_back(0);
        }
        input.result.push_back(temp);
    }

    for (int i = 0; i < input.M; i++){
        for (int j = 0; j < input.G; j++){
            if (input.guestsType[i] == 'C'){
                input.guestsAtH[i] = (input.guestsAtH[i] + 1) % input.N;
            }
            else {
                input.guestsAtH[i] = (input.guestsAtH[i] - 1) % input.N;
            }
        }
        updateMatrix(input.result, input.guestsAtH, i);
    }
}

void updateMatrix(vector<vector<int>> matrix, vector<int> queue, int time){
    for (int i = 0; )
}
