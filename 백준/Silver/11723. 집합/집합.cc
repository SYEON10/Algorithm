#include <iostream>
#include <string>
#include <vector>

using namespace std;

int s = 0;

void Add(const int& x){
    s |= (1 << x);
}

void Remove(const int& x){
    s &= ~(1 << x);
}

void Check(const int& x){
    cout << (((s & (1 << x)) == 0) ? 0 : 1) << '\n';
}

void Toggle(const int& x){
    s ^= (1 << x);
}

void All(){
    s = (1 << 21) - 1;
}

void Empty(){
    s = 0;
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