#include <iostream>

using namespace std;

int binary_exponentiation(int x, int y, int n);

int main() {
	while (!cin.eof()) {
		int x = 0, y = 0, n = 0;
		cin >> x >> y >> n;
        if (n == 0) return 0;

		cout << binary_exponentiation(x, y, n) << "\n";
	}

	return 0;
}

int binary_exponentiation(int x, int y, int n) {
	x = x % n;
	int res = 1;

	while (y) {
		if (y & 1) {
			res = (res * x) % n;
		}
		x = (x * x) % n;
		y = y >> 1;
	}

	return res;
}
