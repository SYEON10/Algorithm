#include <iostream>
#include <cmath>

using namespace std;

void Hanoi(int n, int from, int temp, int to){
    if(n == 0)
        return;
    //전부 B로 옮긴다
    Hanoi(n - 1, from, to, temp); //A -> B
    //나를 C로 옮긴다
    cout << from << ' ' << to << '\n';
    //전부 C로 옮긴다
    Hanoi(n - 1, temp, from, to); //B -> C
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string temp = to_string(pow(2, n));
    int idx = temp.find('.');
    temp = temp.substr(0, idx);
    temp[temp.length() - 1] -= 1;

    cout << temp << '\n';

    if(n <= 20)
        Hanoi(n, 1, 2, 3);

    return 0;
}
