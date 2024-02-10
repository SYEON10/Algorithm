#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;
const int INF = 26;

int PAPERCOUNT = 5;

vector<vector<bool>> board(SIZE, vector<bool> (SIZE));
vector<int> papers(5, PAPERCOUNT);

int Calculate(int idx, int count){
    int ans = INF;

    //기저조건
    if(idx == SIZE * SIZE){
        return min(ans, count);
    }

    int row = idx / SIZE;
    int col = idx % SIZE;

    if(!board[row][col]){
        return Calculate(idx + 1, count);
    }
    if(ans <= count){
        return INF;
    }

    for(int i = PAPERCOUNT - 1; i >= 0; i--){

        if(papers[i] == 0)
            continue;

        bool canAttach = true;

        //1. 붙일 수 있나
        for(int r = 0; r <= i; r++){
            for(int c = 0; c <= i; c++){
                if(!(row + r < SIZE && col + c < SIZE) || !board[row + r][col + c]){
                    canAttach = false;
                }
            }
        }

        if(!canAttach)
            continue;

        //2. 붙일 수 있다면 붙인다
        for(int r = 0; r <= i; r++){
            for(int c = 0; c <= i; c++){
                board[row + r][col + c] = false;
            }
        }

        papers[i]--;

        ans = min(ans, Calculate(idx + 1, count + 1));

        //색종이 떼기
        //papers 다운그레이드하기
        for(int r = 0; r <= i; r++){
            for(int c = 0; c <= i; c++){
                board[row + r][col + c] = true;
            }
        }

        papers[i]++;
    }

    return ans;
}

int main() {

    int count = 0;

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            int x;
            cin >> x;
            if(x == 1)
                board[i][j] = true;
            if(x == 0)
                board[i][j] = false;
        }
    }

    int ans = Calculate(0, 0);

    cout << (ans == INF ? -1 : ans);

    return 0;
}