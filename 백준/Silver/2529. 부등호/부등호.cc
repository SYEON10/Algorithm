#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<bool> bigger;
bool visited[10];
int word[10];
int min_word[10];
int max_word[10];
bool min = false;

void BackTracking(int index){
    if(index == n + 1){
        if(!::min){
            for(int i = 0; i <= n; i++){
                min_word[i] = word[i];
            }
            ::min = true;
        }
        for(int i = 0; i <= n; i++){
            max_word[i] = word[i];
        }
        return;
    }
    for(int num = 0; num <= 9; num++){
        if(index == 0){
            visited[num] = true;
            word[index] = num;
            BackTracking(index + 1);
            visited[num] = false;
        }
        else{
            if(visited[num]) continue;
            if(bigger[index - 1] && word[index - 1] < num){
                visited[num] = true;
                word[index] = num;
                BackTracking(index + 1);
                visited[num] = false;
            }
            else if(!bigger[index - 1] && word[index - 1] > num){
                visited[num] = true;
                word[index] = num;
                BackTracking(index + 1);
                visited[num] = false;
            }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        char eq;
        cin >> eq;
        switch(eq){
            case '<':
                bigger.push_back(true);
                break;
            case '>':
                bigger.push_back(false);
                break;
        }
    }

    BackTracking(0);

    for(int i = 0; i <= n; i++){
        cout << max_word[i];
    }
    cout << '\n';
    for(int i = 0; i <= n; i++){
        cout << min_word[i];
    }

    return 0;
}