#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	
	int n;

	cin >> n;

	deque<int> arr;
	vector<int> input(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	for(int i = 1; i <= n; i++) {
		int store;
		switch (input[n - i]) {
		case 1:
			arr.push_back(i);
			break;
		case 2:
			store = arr.back();
			arr.pop_back();
			arr.push_back(i);
			arr.push_back(store);
			break;
		case 3:
			arr.push_front(i);
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[n - i - 1] << ' ';
	}


	return 0;
}