#include <string>
#include <vector>

using namespace std;

int out[1000001];
int in[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    
    for(int i = 0; i < edges.size(); i++){
        out[edges[i][0]]++;
        in[edges[i][1]]++;
    }
    
    for(int i = 1; i < 1000001; i++){
        if(in[i] == 0 && out[i] >= 2){
            answer[0] = i;
        }
        if(in[i] >= 2 && out[i] == 2){
            answer[3]++;
        }
        if(in[i] >= 1 && out[i] == 0){
            answer[2]++;
        }
    }
    
    answer[1] = out[answer[0]] - answer[2] - answer[3];
    
    return answer;
}