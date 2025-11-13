#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int count = 0;
int SIZE;
const int MAX_SIZE = 20;

bool row[MAX_SIZE];
bool col[MAX_SIZE];
bool right_diagnol[MAX_SIZE]; //왼쪽 대각선 => r + c
bool left_diagnol[MAX_SIZE]; //오른쪽 대각선 => size - c + r - 1

void Back(int r){
    if(r == SIZE){
        ::count++;
        return;
    }

    for(int c = 0; c < SIZE; c++){
        if(row[r] || col[c] || right_diagnol[r + c] || left_diagnol[SIZE - c + r - 1]) continue;
        row[r] = true;
        col[c] = true;
        right_diagnol[r + c] = true;
        left_diagnol[SIZE - c + r - 1] = true;
        Back(r + 1);
        row[r] = false;
        col[c] = false;
        right_diagnol[r + c] = false;
        left_diagnol[SIZE - c + r - 1] = false;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> ::SIZE;

    Back(0);

    cout << ::count;

    return 0;
}