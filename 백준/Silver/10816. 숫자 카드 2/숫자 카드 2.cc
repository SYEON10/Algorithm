#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ExistsNum(const int check, const vector<int> &cards){

    int count = 0;

    int left = 0;
    int right = int(cards.size()) - 1;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(cards[mid] == check){
            //왼쪽에 몇개, 오른쪽에 몇개 있나 확인 -> 이분탐색
            int leftCheck = left;
            int rightCheck = mid - 1;
            int midCheck;

            while(leftCheck <= rightCheck){
                midCheck = (leftCheck + rightCheck) / 2;

                if(cards[midCheck] == check){
                    rightCheck = midCheck - 1;
                }
                else{
                    leftCheck = midCheck + 1;
                }
            }

            left = leftCheck;
            leftCheck = mid + 1;
            rightCheck = right;

            while(leftCheck <= rightCheck){
                midCheck = (leftCheck + rightCheck) / 2;

                if(cards[midCheck] == check){
                    leftCheck = midCheck + 1;
                }
                else{
                    rightCheck = midCheck - 1;
                }
            }

            right = rightCheck;

            count = right - left + 1;
            break;
        }
        if(cards[mid] > check){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return count;
}

int main()
{
    //입력
    int n, m;
    cin >> n;

    vector<int> cards(n);
    for(auto &card : cards){
        cin >> card;
    }

    cin >> m;
    vector<int> checks(m);
    for(auto &check : checks){
        cin >> check;
    }

    //연산 및 출력

    sort(cards.begin(), cards.end());

    for(const auto &check : checks){
        cout << ExistsNum(check, cards) << ' ';
    }

    return 0;
}