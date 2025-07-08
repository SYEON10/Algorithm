#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(0)->sync_with_stdio(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<int> buildings;
    vector<int> parents(n + 1, 0);
    vector<bool> sources(n + 1, false);
    vector<vector<int>> building_source(n + 1, vector<int>());
    vector<vector<int>> adj_list(n + 1, vector<int>()); //from : source, to : building
    queue<int> q;

    for (int i = 0; i < m; i++) {
        int building;
        cin >> building;
        buildings.push_back(building);
        q.push(building);
    }

    for (int i = 1; i <= n; i++) {
        int count, source;
        cin >> count;
        while (count--) {
            cin >> source;
            building_source[i].push_back(source);
        }
    }

    for (int i = 0; i < n - m; i++) {
        int building, count;
        cin >> building >> count;
        parents[building] = count;
        while (count--) {
            int source;
            cin >> source;
            adj_list[source].push_back(building);
        }
    }


    while (!q.empty() && t > 0) {
        t--;
        vector<int> currentBuildings;
        while (!q.empty()) {
            currentBuildings.push_back(q.front());
            q.pop();
        }

        //빌딩에서 만들어진 소스 돌면서 중복 제외 빌딩들 parent 차감
        for (auto building : currentBuildings) {
            for (auto created_source : building_source[building]) {
                if (sources[created_source]) continue;
                sources[created_source] = true;

                for (auto uncreated_building : adj_list[created_source]) {
                    parents[uncreated_building]--;
                    if (parents[uncreated_building] == 0)
                    {
                        q.push(uncreated_building);
                        buildings.push_back(uncreated_building);
                    }
                }
            }
        }
    }

    cout << buildings.size() << '\n';
    sort(buildings.begin(), buildings.end());

    for (auto b : buildings) {
        cout << b << ' ';
    }

    return 0;
}