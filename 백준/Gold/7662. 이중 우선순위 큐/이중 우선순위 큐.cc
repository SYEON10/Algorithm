#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        priority_queue<int> max_pq;
        priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
        
        unordered_map<int, int> max_map;
        unordered_map<int, int> min_map;

        while(n--){
            char cmd;
            int param;
            cin >> cmd >> param;

            if(cmd == 'I'){
                max_pq.push(param);
                min_pq.push(param);
            }
            if(cmd == 'D'){
                if(param == 1){
                    while(!max_pq.empty() && max_map[max_pq.top()] != 0){
                        max_map[max_pq.top()]--;
                        max_pq.pop();
                    }

                    if(max_pq.empty()) continue;

                    min_map[max_pq.top()]++;
                    max_pq.pop();
                }
                else{
                    while(!min_pq.empty() && min_map[min_pq.top()] != 0){
                        min_map[min_pq.top()]--;
                        min_pq.pop();
                    }

                    if(min_pq.empty()) continue;

                    max_map[min_pq.top()]++;
                    min_pq.pop();
                }
            }
        }

        while(!max_pq.empty() && max_map[max_pq.top()] != 0){
            max_map[max_pq.top()]--;
            max_pq.pop();
        }

        while(!min_pq.empty() && min_map[min_pq.top()] != 0){
            min_map[min_pq.top()]--;
            min_pq.pop();
        }

        if(max_pq.empty() || min_pq.empty()) cout << "EMPTY" << '\n';
        else cout << max_pq.top() << ' ' << min_pq.top() << '\n';
    }
    return 0;
}