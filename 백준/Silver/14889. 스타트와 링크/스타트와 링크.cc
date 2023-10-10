#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. 조합 구하기
//2. 조합에 대한 점수 구하기
//3. 최솟값 업데이트(main)

static int number;

void CreateCombinationTable(const int &n, vector<pair<vector<int>, vector<int>>>& out_Table){
    vector<int> index(n);

    for(int i = 0; i < number; i++){
        index[i] = 1;
    }

    do{
        pair<vector<int>, vector<int>> comb;
        for(int i = 0; i < n; i++){
            if(index[i] == 1)
                comb.first.push_back(i);
            else comb.second.push_back(i);
        }
        out_Table.push_back(comb);
    }
    while(prev_permutation(index.begin(), index.end()));
}

int CalculateScore(const vector<vector<int>> &table, const vector<int> &comb, const int& n){
    int add = 0;

    for(int i = 0; i < number; i++){
        for(int j = i; j < number; j++){
            add += table[comb[j]][comb[i]];
            add += table[comb[i]][comb[j]];
        }
    }

    return add;
}

int main() {

    int n;
    int min = 100; //최대 능력치
    cin >> n;

    number = n / 2;
    vector<vector<int>> table(n);
    vector<pair<vector<int>, vector<int>>> combinationTable;

    for(int i = 0; i < n; i++){
        vector<int> col(n);
        for(int j = 0; j < n; j++){
            cin >> col[j];
        }
        table[i] = col;
    }

    CreateCombinationTable(n, combinationTable);

    for(const auto &comb : combinationTable){
        min = std::min(std::abs(CalculateScore(table, comb.first, n) - CalculateScore(table, comb.second, n)), min);
    }

    cout << min;

    return 0;
}
