/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671
#include <iostream>

using namespace std;

int binary_exponentiation(int x, int y, int n);

int main() {
	int T;
	cin >> T;

	while (T--) {
		int x, y, n;
		cin >> x >> y >> n;

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
