#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Play(const vector<int> &order, const vector<vector<int>> &players){
    int out = 0, score = 0, nowPlayer = -1;
    int Count = int(players.size());
    int nowScore;
    vector<bool> ground(4);

    for(int inning = 0; inning < Count; inning++){
        //이닝 바뀔 시 초기화
        ground.assign(4, false);
        out = 0;

        while(out < 3){
            nowPlayer = (nowPlayer + 1) % 9;
            nowScore = players[inning][order[nowPlayer]];

            if(nowScore == 0){
                out++;
                continue;
            }
            for(int i = 3; i > 0; i--){
                if(ground[i]){
                    if(i + nowScore > 3){
                        score++;
                    }
                    else {
                        ground[i + nowScore] = true;
                    }
                    ground[i] = false;
                }
            }
            if(nowScore == 4) {
                score++;
            }
            else ground[nowScore] = true;
        }
    }

    return score;
}

// 8! x 50 x 연산비용 = 20'000'000 X 연산비용 -> 브루트포스
int main()
{
    int inning, maxScore = 0;
    cin >> inning;

    //[이닝][플레이어 번호] -> 이닝에 다른 점수
    vector<vector<int>> players(inning, vector<int>(9));
    vector<int> order(9); //순서 -> 플레이어 인덱스

    for(int i = 0; i < 9; i++){
        order[i] = i;
    }

    for(int count = 0; count < inning; count++){
        for(int idx = 0; idx < 9; idx++){
            cin >> players[count][idx];
        }
    }

    do{
        swap(order[0], order[3]);
        maxScore = max(maxScore, Play(order, players));
        swap(order[0], order[3]);
    }
    while(next_permutation(order.begin() + 1, order.end()));

    cout << maxScore;

    return 0;
}