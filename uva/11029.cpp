/// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1970
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int binary_exponentiation(int x, int y);

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, p;
        cin >> n >> p;
        int last_three = binary_exponentiation(n, p);
        auto power = p * log10(n);
        auto first_three = floor(pow(10, power - floor(power) + 2));

        cout << first_three << "..." << setw(3) << setfill('0') <<  last_three << "\n";
    }
    return 0;
}

int binary_exponentiation(int x, int y) {
	x = x % 1000;
	int res = 1;

	while (y) {
		if (y & 1) {
			res = (res * x) % 1000;
		}
		x = (x * x) % 1000;
		y = y >> 1;
	}

	return res;
}
