#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n, a, b, answer;
    cin >> n;

    vector<vector<int>> cache(10);

    //0~9 반복되는 구간 캐싱
    for(int i = 0; i < 10; i++){
        vector<int> temp(1, i);

        int num = i;
        while(true){
            num = (num * i) % 10;
            if(num != i)
                temp.push_back(num);
            else break;
        }

        cache[i] = temp;
    }

    while(n--){
        cin >> a >> b;
        
        a %= 10;

        if(cache[a].size() == 1)
            answer = cache[a][0];
        else answer = cache[a][(b - 1) % cache[a].size()];

        if(answer == 0)
            cout << 10 << '\n';
        else cout << answer << '\n';
    }

    return 0;
}