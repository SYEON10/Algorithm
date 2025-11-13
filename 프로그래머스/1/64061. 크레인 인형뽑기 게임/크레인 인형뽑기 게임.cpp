#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> basket;

    for(auto move : moves){
        int line = move - 1;
        for(int i = 0; i < board.size(); i++) {
            if(board[i][line] == 0) continue;
            if(!basket.empty() && board[i][line] == basket.top()) {
                basket.pop();
                answer += 2;
            }
            else {
                basket.push(board[i][line]);
            }
            board[i][line] = 0;
            break;
        }
    }

    return answer;
}