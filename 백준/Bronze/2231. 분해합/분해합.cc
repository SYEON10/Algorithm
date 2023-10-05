#include <iostream>

using namespace std;

int findConstructor(int n) {
	int sum;

	for (int i = 1; i < n; i++) {
		int temp = i;
		sum = i;

		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n) {
			return i;
		}
	}

	return 0;
}

int main() {
	
	int n;
	cin >> n;
	cout << findConstructor(n);

	return 0;
}