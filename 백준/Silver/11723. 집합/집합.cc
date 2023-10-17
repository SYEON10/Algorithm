#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> S(21, false);

void Add(int x){
    S[x] = true;
}

void Remove(int x){
    S[x] = false;
}

void Check(int x){
    cout << S[x] << '\n';
}

void Toggle(int x){
    S[x] = !S[x];
}

void All(){
    S.assign(21, true);
}

void Empty(){
    S.assign(21, false);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    string command;
    cin >> n;

    while(n--){
        cin >> command;

        if(command == "add")            {cin >> x; Add(x);}
        else if(command == "remove")    {cin >> x; Remove(x);}
        else if(command == "check")     {cin >> x; Check(x);}
        else if(command == "toggle")    {cin >> x; Toggle(x);}
        else if (command == "all")      All();
        else if(command == "empty")     Empty();
    }

    return 0;
}