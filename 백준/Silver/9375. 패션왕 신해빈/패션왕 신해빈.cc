#include <iostream>
#include <map>
#include <string>

using namespace std;

//중복 없이, key-value 데이터 -> map
//조합 문제

int main(){

    int count, n;
    cin >> count;

    while(count--){
        int cases = 1;
        map<string, int> clothes;

        cin >> n;

        for(int i = 0; i < n; i++){
            string name, category;
            cin >> name >> category;

            clothes[category]++;
        }

        for(auto cloth : clothes){
            cases *= (cloth.second + 1);
        }

        cases -= 1; //안입는경우

        cout << cases << '\n';
    }

    return 0;
}