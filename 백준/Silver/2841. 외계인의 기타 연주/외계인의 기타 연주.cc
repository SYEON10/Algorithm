#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, p;
    int line, fret;
    int count = 0;

    cin >> n >> p;

    vector<vector<int>> lines(6, {0}); //6개의 줄

    while(n--){
        bool isPushed = false;
        cin >> line >> fret;
        for(int i = 0; i < lines[line - 1].size(); i++){
            if(lines[line - 1][i] > fret){
                lines[line - 1].erase(lines[line - 1].begin() + i);
                count++;
                i--;
            }
            if(lines[line - 1][i] == fret)
                isPushed = true;
        }

        if(!isPushed){
            count++;
            lines[line - 1].push_back(fret);
        }
    }

    cout << count;

    return 0;
}