#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){

    //입력
    int N, B, C;
    cin >> N;
    long long count = N;
    vector<int> A(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;

    for(const auto &a : A){
        if(a - B <= 0){
            continue;
        }

        count += (a - B) / C;

        if((a - B) % C > 0){
            count++;
        }
    }

    cout << count;

    return 0;
}