#include <iostream>
#include <list>
#include <string>
using namespace std;

list<char> output;
list<char> ::iterator iter;

void keyLogger(string input) {

	output.clear();
	iter = output.begin();

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			if (!(iter == output.begin())) {
				iter--;
			}
		}
		else if (input[i] == '>') {
			if (!(iter == output.end())) {
				iter++;
			}
		}
		else if (input[i] == '-') {
			if (!(iter == output.begin())) {
				iter = output.erase(--iter);
			}
		}
		else {
			output.insert(iter, input[i]);
		}
	}

	for (iter = output.begin(); iter != output.end(); iter++) {
		cout << *iter;
	}
	cout << '\n';
}

int main() {

	int n;
	cin >> n;

	while (n--) {
		string input;
		cin >> input;
		keyLogger(input);
	}

	return 0;
}