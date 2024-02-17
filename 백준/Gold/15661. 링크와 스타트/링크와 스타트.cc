#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int SIZE;
int answer = INT_MAX;
vector<vector<int>> matrix;
vector<bool> checker;

void Calculate(){
    vector<int> teamS;
    vector<int> teamL;

    int countS = 0;
    int countL = 0;

    for(int i = 0; i < n; i++){
        if(checker[i]){
            teamS.push_back(i);
        }
        else {
            teamL.push_back(i);
        }
    }

    for(int i = 0; i < teamS.size(); i++){
        for(int j = 0; j < teamS.size(); j++){
            //스타트팀 계산
            countS += matrix[teamS[i]][teamS[j]];
        }
    }

    for(int i = 0; i < teamL.size(); i++){
        for(int j = 0; j < teamL.size(); j++){
            //링크팀 계산
            countL += matrix[teamL[i]][teamL[j]];
        }
    }

    int result = abs(countS - countL);
    answer = min(answer, result);
}

void Backtracking(int count, int start){
    if(count == n){
        return;
    }

    for(int i = start; i < n; i++){
        if(!checker[i]){
            checker[i] = true;
            Calculate();
            Backtracking(count + 1, i);
            checker[i] = false;
        }
    }
}


int main() {

    cin >> n;
    SIZE = n / 2;
    matrix.assign(n, vector<int>(n));
    checker.assign(n, false);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    Backtracking(0, 0);

    cout << answer;

    return 0;
}