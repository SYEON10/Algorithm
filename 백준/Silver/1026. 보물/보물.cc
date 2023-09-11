#include <iostream>
#include <vector>

using namespace std;

vector<int> arrA, arrB, arrC;

void advancedBubbleSort(int n) {

	for (int i = 0; i < n - 1; i++) {
		int isSwap = false;
		for (int j = 0; j < n - 1; j++) {
			if (arrA[j] > arrA[j + 1]) {
				swap(arrA[j], arrA[j + 1]);
				isSwap = true;
			}
		}

		if (!isSwap) {
			break;
		}
	}
}

void BubbleSort(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			if (arrB[i] > arrB[j]) {
				arrC[i]--;
			}
			else {
				arrC[j]--;
			}
		}
	}
}

void addMin(int n) {

	int add = 0;
	BubbleSort(n);
	advancedBubbleSort(n);

	for (int i = 0; i < n; i++) {
		add += arrA[arrC[i]] * arrB[i];
	}

	cout << add;
}

int main() {

	int n;

	cin >> n;

	arrA.assign(n, 0);
	arrB.assign(n, 0);
	arrC.assign(n, n - 1);

	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> arrB[i];
	}

	addMin(n);

}