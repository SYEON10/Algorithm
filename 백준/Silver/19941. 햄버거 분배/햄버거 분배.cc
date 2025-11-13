#include <iostream>
#include <string>

using namespace std;

int main() {

    int n, k, count = 0;
    cin >> n >> k;
    string input;

    cin >> input;

    for(int i = 0; i < n; i++) {
        if(input[i] == 'P') {
            for(int j = k; j >= -k; j--) {
                if(i - j < 0 && i - j > n) continue;
                if(input[i - j] == 'H') {
                    input[i - j] = 'E';
                    count++;
                    break;
                }
            }
        }
    }

    cout << count;

    return 0;
}
