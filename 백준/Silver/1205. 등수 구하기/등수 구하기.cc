#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, score, p, result;
    cin >> n >> score >> p;

    vector<int> ranking(p, -1);

    for(int i = 0; i < n; i++){
        cin >> ranking[i];
    }

    //코너케이스
    //랭킹리스트가 꽉 차있을 때, 같은 수로 꽉 차있을 때..., 들어온 수가 없을 때
    for(int i = 0; i < p; i++){
        if(score > ranking[i]){
            cout << i + 1;
            return 0;
        }
        if(score == ranking[i]){
            for(int j = i + 1; j < p; j++){
                if(score == ranking[j])
                    continue;
                else{
                    cout << i + 1;
                    return 0;
                }
            }
            break;
        }
    }

    cout << -1;

    return 0;
}