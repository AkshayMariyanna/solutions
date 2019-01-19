/// https://www.spoj.com/problems/ZSUM/
#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007

unsigned long long aton(unsigned long long a, unsigned long long n) {
	a = a%MOD;
	unsigned long long res = 1;
	
	while (n != 0) {
		if (n & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	
	return res;
}

int main() {
	while (true) {
		unsigned long long n, k;
		cin >> n >> k;
		
		if (n == 0 && k == 0)
			return 0;
		
		// 2(n-1)^k + 2(n-1)^(n-1) + n^k + n^n
		unsigned long long term1 = (2 * aton(n-1, k)) % MOD;
		unsigned long long term2 = (2 * aton(n-1, n-1)) % MOD;
		unsigned long long term3 = (term1 + aton(n, k)) % MOD;
		unsigned long long term4 = (term2 + aton(n, n)) % MOD;
		
		cout << (term3 + term4) % MOD << "\n";
		
	}
}
