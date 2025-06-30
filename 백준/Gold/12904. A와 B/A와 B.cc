#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string S, goal;
    cin >> S >> goal;

    deque<char> T(goal.begin(), goal.end());
    bool rev = false;

    while (T.size() > S.size()) {
        if (!rev) {
            if (T.back() == 'A') {
                T.pop_back();
            } else if (T.back() == 'B') {
                T.pop_back();
                rev = !rev;
            }
        } else {
            if (T.front() == 'A') {
                T.pop_front();
            } else if (T.front() == 'B') {
                T.pop_front();
                rev = !rev;
            }
        }
    }

    if (rev) {
        reverse(T.begin(), T.end());
    }

    string result(T.begin(), T.end());
    cout << (result == S ? 1 : 0);
    return 0;
}
