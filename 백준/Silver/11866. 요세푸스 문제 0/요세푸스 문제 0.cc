#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n, k;
	queue<int> circle;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		circle.push(i);
	}

	cout << '<';

	while (n--) {

		for (int i = 0; i < k - 1; i++) {
			circle.push(circle.front());
			circle.pop();
		}

		cout << circle.front();
		circle.pop();

		if (n > 0) {
			cout << ", ";
		}
	}

	cout << '>';

}