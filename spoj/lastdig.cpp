#include <iostream>

using namespace std;

int binary_exponentiation(unsigned int x, unsigned int y);

int main() {
	int T;
	cin >> T;

	while (T--) {
		unsigned int x, y;
		cin >> x >> y;

		cout << binary_exponentiation(x, y) << "\n";
	}

	return 0;
}

int binary_exponentiation(unsigned int x, unsigned int y) {
	x = x % 10;
	int res = 1;

	while (y) {
		if (y & 1) {
			res = (res * x) % 10;
		}
		x = (x * x) % 10;
		y = y >> 1;
	}

	return res;
}