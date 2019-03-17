#include <iostream>

#define MOD97 1000000007

using namespace std;
typedef long long ll;

void fib(ll n, ll & fn, ll & fn1) {
  if (n == 0) {
    fn = 0;
    fn1 = 1;
    return;
  }
  fib(n >> 1, fn , fn1);
  ll c = (fn * ((((2 * fn1) % MOD97) - fn + MOD97) % MOD97)) % MOD97;
  ll d = (((fn1 * fn1) % MOD97) + ((fn * fn) % MOD97)) % MOD97;
  if (n & 1) {
    fn = d;
    fn1 = (c + d) % MOD97;
  } else {
    fn = c;
    fn1 = d;
  }
}

int main() {
  ll T;
  cin >> T;

  while (T--) {
    ll N, M;
    cin >> N >> M;
    ll fn, fn1, fm1, fm2;
    fib(N, fn, fn1);
    fib(M + 1, fm1, fm2);
    cout << (MOD97 - fn1 + fm2) % MOD97 << "\n";
  }
}
