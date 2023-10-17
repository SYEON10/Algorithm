#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> alphabet(26, false);

bool WordChecker(const string& word){

    alphabet.assign(26, false);

    int before = -1;
    for(const auto & c : word){
        int n = c - 'a';
        if(n != before && alphabet[n])
            return false;
        alphabet[n] = true;
        before = n;
    }

    return true;
}

int main(){

    int n;
    int count = 0;
    string word;
    cin >> n;

    while(n--){
        cin >> word;

        if(WordChecker(word))
            count++;
    }

    cout << count;

    return 0;
}