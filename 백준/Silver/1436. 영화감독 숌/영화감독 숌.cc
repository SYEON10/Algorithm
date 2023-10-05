#include <iostream>

using namespace std;

int getEndNumber(int n) {
	int num = 666 - 1;

	while (n > 0) {
		string s = to_string(++num);
		if (s.find("666") != s.npos){
			n--;
			
		}
	}

	return num;
}

int main() {

	int n;
	cin >> n;

	cout << getEndNumber(n);

	return 0;
}