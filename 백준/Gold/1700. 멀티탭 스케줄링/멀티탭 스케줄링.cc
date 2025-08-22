#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//플러그를 빼는 횟수 최소화
//

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    set<int> plug;
    vector<int> schedule(k);

    for(int i = 0; i < k; i++){
        cin >> schedule[i];
    }

    int count = 0;
    for(int i = 0; i < k; i++){
        if(count == n) break;
        if(plug.find(schedule[i]) != plug.end()) continue;
        count++;
        plug.insert(schedule[i]);
    }

    int pointer = n;
    int result = 0;

    // 1 2 3 4 5 3 4 3 7 1 2 1 2 1 2 1 2
    // 3구

    //3개 다 갈아끼워지지 않는 선까지 Most Frequent를 

    for(int i = count; i < k; i++){
        if(plug.find(schedule[i]) != plug.end()) continue;
        
        int latest = INT32_MAX;
        int latestIndex = -1;
        for(int p : plug){
            int findIndex = -1;
            for(int j = i; j < k; j++){
                if(p == schedule[j]){
                    findIndex = j;
                    break;
                }
            }
            if(findIndex == -1){ //찾지 못한 경우
                latest = p;
                break;
            }
            if(findIndex > latestIndex){
                latest = p;
                latestIndex = findIndex;
            }
        }

        result++;
        plug.erase(latest);
        plug.insert(schedule[i]);
    }

    cout << result;

    return 0;
}