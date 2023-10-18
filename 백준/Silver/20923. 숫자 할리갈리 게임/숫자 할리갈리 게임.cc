#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void moveCard(deque<int> &deq, deque<int> &ground){
    while(!ground.empty()){
        deq.push_back(ground.back());
        ground.pop_back();
    }
}

pair<int, int> Game(int n, vector<deque<int>> &deq, vector<deque<int>> &ground){
    bool turn = false;

    while(n--){
        int card = deq[turn].front();
        ground[turn].push_front(card);
        deq[turn].pop_front();

        if(deq[turn].empty())
            break;

        int bell = -1;
        if(card == 5){
            bell = 0;
        }
        else if(!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)){
            bell = 1;
        }

        if(bell != -1){
            moveCard(deq[bell], ground[!bell]);
            moveCard(deq[bell], ground[bell]);
        }

        turn = !turn;
    }

    return make_pair(deq[0].size(), deq[1].size());
}

int main() {

    int count, n;
    vector<deque<int>> deq(2), ground(2);

    cin >> count >> n;
    
    int dodo, susu;
    while(count--){
        cin >> dodo >> susu;
        deq[0].push_front(dodo);
        deq[1].push_front(susu);
    }


    pair<int, int> p = Game(n, deq, ground);

    if(p.first == p.second)
        cout << "dosu";
    if(p.first > p.second)
        cout << "do";
    if(p.first < p.second)
        cout << "su";

    return 0;
}