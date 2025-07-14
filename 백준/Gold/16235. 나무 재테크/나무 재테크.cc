#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct tree{
    int age, r, c;
    bool operator< (const tree& other) const {
        return age < other.age;
    }
};

vector<pair<int, int>> dir{{1, 0}, {0, 1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {-1, 0}, {0, -1}};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    vector<vector<int>> curr(n + 1, vector<int>(n + 1, 5));
    vector<vector<deque<int>>> deq(n + 2, vector<deque<int>>(n + 2));

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            cin >> A[r][c];
        }
    }

    vector<tree> input(m);
    for(int i = 0; i < m; i++){
        int r, c, age;
        cin >> r >> c >> age;
        input[i] = {age, r, c};
    }

    sort(input.begin(), input.end());

    for(const auto& t : input){
        deq[t.r][t.c].push_back(t.age);
    }

    while(k--){
        vector<pair<int, int>> breed;
        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= n; c++){
                int add = 0;
                int pop_count = 0;
                for(int i = 0; i < deq[r][c].size(); i++){
                    if(curr[r][c] < deq[r][c][i]){
                        pop_count = deq[r][c].size() - i;
                        break;
                    }
                    curr[r][c] -= deq[r][c][i];
                    deq[r][c][i] += 1;
                    if(deq[r][c][i] % 5 == 0){
                        breed.push_back({r, c});
                    }
                }
                while(pop_count--){
                    add += deq[r][c].back() / 2;
                    deq[r][c].pop_back();
                }
                curr[r][c] += add + A[r][c];
            }
        }

        for(auto& b : breed){
            for(auto& d : dir){
                deq[b.first + d.first][b.second + d.second].push_front(1);
            }
        }
    }

    int count = 0;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            count += deq[r][c].size();
        }
    }

    cout << count;

    return 0;
}