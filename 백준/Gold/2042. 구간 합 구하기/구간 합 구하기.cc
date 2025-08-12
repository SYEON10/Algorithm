#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, k;
long long nums[1000'001];
long long tree[2000'002];

long long find(int start, int end, int index, int from, int to) {
    if (start == from && end == to) {
        return tree[index];
    }

    long long value = 0;
    int mid = (start + end) / 2;
    if (mid >= from && mid < to) {
        value += find(start, mid, index * 2, from, mid);
        value += find(mid + 1, end, index * 2 + 1, mid + 1, to);
    }
    else if (from > mid) {
        value = find(mid + 1, end, index * 2 + 1, from, to);
    }
    else {
        value = find(start, mid, index * 2, from, to);
    }

    return value;
}

//index번째 노드를 num으로 변경하는 함수
long long change(int start, int end, int index, int target, long long num) {
    if (start == end) {
        return tree[index] = num;
    }
    int mid = (start + end) / 2;
    if (mid >= target) tree[index] = tree[index * 2 + 1] + change(start, mid, index * 2, target, num);
    else tree[index] = tree[index * 2] + change(mid + 1, end, index * 2 + 1, target, num);
    return tree[index];
}

//segtree 자료구조를 뭘 쓰면 좋을까... -> CBT인데 당연히 Array지;
long long DFS(int start, int end, int index) {
    if (start == end) {
        tree[index] = nums[start];
        return tree[index];
    }
    int mid = (start + end) / 2;
    tree[index] += DFS(start, mid, index * 2);
    tree[index] += DFS(mid + 1, end, index * 2 + 1);
    return tree[index];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    DFS(1, n, 1);

    for (int i = 0; i < m + k; i++) {
        int cmd;
        long long a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            change(1, n, 1, a, b);
        }
        if (cmd == 2) {
            cout << find(1, n, 1, a, b) << '\n';
        }
    }

    return 0;
}