#include <iostream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int>& input, int count) {

	int temp;

	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (input[j] > input[j + 1]) {
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}

	return input;
}

int main() {

	int count;
	cin >> count;

	vector<int> input;
	int temp;

	for(int i = 0; i < count; i++){
		cin >> temp;
		input.push_back(temp);
	}

	BubbleSort(input, count);

	for (int i = 0; i < count; i++) {
		cout << input[i] << '\n';
	}

	return 0;
}