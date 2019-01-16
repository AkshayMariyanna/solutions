#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	bool mapOPrime[100005];
	
	while (T--) {
		int s, e;
		cin >> s >> e;
		int n = e - s + 1;
		memset(mapOPrime, 1, n);
		int sq = sqrt(e);
		for (int i = 2; i <= sq; i++) {
			int j = i - (s % i);
			j = j == i ? 0 : j;
			for (; j < n; j += i) {
				int cN = s + j;
				if (cN == i) {
					continue;
				}
				mapOPrime[j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			if (mapOPrime[i] && s + i != 1) {
				cout << s + i << endl;
			}
		}
		cout << endl;
	}
}