/// https://www.spoj.com/problems/LOCKER/
#include <iostream>
#define MOD97 1000000007

using namespace std;

typedef long long ll;

ll binomial_exponentiation(ll l);

int main() {
	int T;
	cin >> T;

	while (T--) {
		ll n;
		cin >> n;
		if (n == 1) {
			cout << n << "\n";
			continue;
		}

		ll l = ((n - 2) / 3);
		int l3 = binomial_exponentiation(l);
		l = ((n - 2) % 3) + 2;

		cout << (l3 *(l)) % MOD97 << "\n";		
	}

	return 0;
}

ll binomial_exponentiation(ll l) {
	ll res = 1;
	ll n = 3;
	while (l > 0) {
		if (l & 1) {
			res = (res * n) % MOD97;
		}
		n = (n * n) % MOD97;
		l >>= 1;
	}

	return res;
}

