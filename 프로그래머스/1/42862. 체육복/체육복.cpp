#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
        
    vector<int> students(n + 1, 1); //0 lost, 1 idle, 2 reserve
    
    for(const auto& reserveStudent : reserve){
        students[reserveStudent] = 2;
    }
    
    for(const auto& lostStudent : lost){
        students[lostStudent]--;
    }
    
    for(int i = 1 ; i <= n; i++){
        if(students[i] == 0){
            if(students[i - 1] == 2){
                //빌리기
                students[i]++;
                students[i - 1]--;
                answer++;
            }
            else if(students[i + 1] == 2){
                //빌리기
                students[i]++;
                students[i + 1]--;
                answer++;
            }
        }
        else answer++;
    }
    
    return answer;
}