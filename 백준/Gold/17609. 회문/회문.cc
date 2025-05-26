#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Checker(string str, int left, int right) {
    while (left < right) {
        if (str[left] == str[right]) {
            left++;
            right--;
            continue;
        }
        return false;
    }
    return true;
}

int Checker(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] == str[right]) {
            left++;
            right--;
            continue;
        }

        if (Checker(str, left, right - 1) || Checker(str, left + 1, right)) {
            return 1;
        }
        else return 2;
    }

    return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        string input;
        cin >> input;

        cout << Checker(input) << '\n';
    }

    return 0;
}