#include <iostream>

#define ANS_TO_LIFE 42

using namespace std;

int main() {
	int c;
	cin >> c;
	while (c != ANS_TO_LIFE) {
		cout << c << endl;
		if (cin.eof())
			return 0;
		cin >> c;
	}

	return 0;
}
