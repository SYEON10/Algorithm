#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long getATK(const vector<long long> &stat){
    return stat[0]
    * (100 + stat[1])
    * (100 * (100 - min(stat[2], 100ll)) + (min(stat[2], 100ll) * stat[3]))
    * (100 + stat[4]);
}

long long getNewATK(vector<long long> stat, const vector<long long>& beforeWeapon, const vector<long long>& newWeapon){
    for(int i = 0; i < 5; i++){
        stat[i] = stat[i] - beforeWeapon[i] + newWeapon[i];
    }

    return getATK(stat);
}

void printATKChange(long long nowATK, long long newATK){
    if(nowATK > newATK){
        cout << "-";
    }
    else if(nowATK < newATK) {
        cout << "+";
    }
    else{
        cout << "0";
    }

    cout << '\n';
};

int main()
{
    const int cree = 0;
    const int pabu = 1;

    vector<vector<long long>> stats(2, vector<long long>(5));
    vector<vector<long long>> weapons(2, vector<long long>(5));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            cin >> stats[i][j];
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            cin >> weapons[i][j];
        }
    }

    long long nowCreeATK = getATK(stats[cree]);
    long long newCreeATK = getNewATK(stats[cree], weapons[cree], weapons[pabu]);

    long long nowPabuATK = getATK(stats[pabu]);
    long long newPabuATK = getNewATK(stats[pabu], weapons[pabu], weapons[cree]);

    printATKChange(nowCreeATK, newCreeATK);
    printATKChange(nowPabuATK, newPabuATK);

    return 0;
}