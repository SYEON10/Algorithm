#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, p, l, count = 0;
    cin >> n >> m;

    vector<int> lectures(n, 0);

    for(int i = 0; i < n; i++){ //n번 반복
        cin >> p >> l;

        vector<int> lecture(p, 0);
        for(int j = 0; j < p; j++){
            cin >> lecture[j];
        }

        if(l > p){
            lectures[i] = 1;
            continue;
        }

        sort(lecture.begin(), lecture.end(), greater<>());
        lectures[i] = lecture[l - 1];
    }

    sort(lectures.begin(), lectures.end());

    for(const auto& lec : lectures){
        if((m -= lec) >= 0){
            count++;
        } else break;
    }

    cout << count;

    return 0;
}