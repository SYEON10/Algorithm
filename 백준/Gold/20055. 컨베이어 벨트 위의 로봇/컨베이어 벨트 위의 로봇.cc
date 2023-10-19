#include <iostream>
#include <deque>

using namespace std;

using space = pair<int, bool>;

void Rotate(deque<space> &belt){
    belt.push_front(belt.back());
    belt.pop_back();
}

void MoveRobot(const int n, deque<space> &belt){
    for(int i = n - 2; i >= 0; i--){
        if(belt[i].second && (belt[i + 1].first > 0) && !belt[i + 1].second){
            belt[i].second = false;
            belt[i + 1].second = true;
            belt[i + 1].first--;
        }
    }
}

int Progress(const int n, const int k, deque<space> &belt){
    int step = 0;
    int end = 0;

    while(end < k){
        //벨트 회전
        Rotate(belt);
        belt[n-1].second = false;

        //로봇 이동
        MoveRobot(n, belt);
        belt[n-1].second = false;

        //로봇 올림
        if(belt[0].first > 0){
            belt[0].second = true;
            belt[0].first--;
        }

        //종료 여부 체크
        end = 0;
        for(const auto& b : belt){
            if(b.first == 0)
                end++;
        }

        step++;
    }

    return step;
}

int main() {

    int n, k;
    cin >> n >> k;

    deque<space> belt(2 * n);
    for(int i = 0; i < 2 * n; i++)
        cin >> belt[i].first;

    cout << Progress(n, k, belt);

    return 0;
}