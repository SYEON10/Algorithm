#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    string temp;
    vector<queue<string>> lines(n);
    char sep = ' ';


    for(int i = 0; i < n; i++){
        getline(cin, temp, '\n');

        string buf;
        istringstream is(temp);
        while(getline(is, buf, sep)){
            lines[i].push(buf);
        }
    }

    getline(cin, temp, '\n');
    string buf;
    istringstream is(temp);
    int possible = 0;

    while(getline(is, buf, sep)){
        for(int i = 0; i < n; i++){
            if(!lines[i].empty() && lines[i].front() == buf){
                lines[i].pop();
                possible = 0;
                break;
            }
            possible++;
        }
        if(possible == n) {
            cout << "Impossible";
            break;
        }
    }

    if(possible == n)
        return 0;

    for(int i = 0; i < n; i++){
        if(!lines[i].empty()){
            cout << "Impossible";
            possible = n;
            break;
        }
    }

    if(possible != n)
        cout << "Possible";

    return 0;
}