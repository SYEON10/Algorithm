#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

const int SIZE = 26;

int TopologicalSort(vector<int> parents_count, const vector<vector<int>>& adj_list, const vector<int>& costs) {
    queue<pair<int, int>> q;
    vector<int> DP(SIZE, 0);

    int timer = 0;

    for (int i = 0; i < SIZE; i++) {
        if (parents_count[i] == 0) {
            q.push({ i, costs[i] });
        }
    }

    while (!q.empty()) {
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        timer = max(timer, time);

        for (auto next : adj_list[node]) {
            parents_count[next]--;
            DP[next] = max(DP[next], time);
            if (parents_count[next] == 0) {
                q.push({ next, DP[next] + costs[next] });
            }
        }
    }

    return timer;
}

vector<string> split(string line) {
    vector<string> result;
    line += ' ';
    string tmp;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            result.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp += line[i];
    }
    return result;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    vector<int> costs(SIZE, 0);
    vector<int> parents_count(SIZE, -1);
    vector<vector<int>> adj_list(SIZE, vector<int>());

    string line;
    int node, cost;
    string required;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<string> tmp = split(line);
        node = line[0] - 'A';
        cost = stoi(tmp[1]);
        costs[node] = cost;
        parents_count[node] = 0;
        if (tmp.size() == 3) {
            for (auto c : tmp[2]) {
                adj_list[c - 'A'].push_back(node);
            }
            parents_count[node] += tmp[2].size();
        }
    }

    cout << TopologicalSort(parents_count, adj_list, costs);

    return 0;
}