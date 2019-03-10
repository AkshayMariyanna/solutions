#include <iostream>

#define MOD97 1000000007

using namespace std;

typedef long long ll;

void fib(ll n, ll & x, ll & x1) {
  if (n == 0) {
    x = 0; x1 = 1; return;
  }
  fib(n >> 1, x, x1);
  ll c = (x * (2 * x1 - x)) % MOD97;
  ll d = ((x * x) % MOD97 + (x1 * x1) % MOD97) % MOD97;
  if (n & 1) {
    x = d;
    x1 = (c + d) % MOD97;
  } else {
    x = c;
    x1 = d;
  }
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    ll N;
    cin >> N;

    if (N == 0)
      cout << 0;
    else if (N == 1)
      cout << 2;
    else {
      ll x, x1;
      fib(N + 1, x, x1);
      cout << (x + x1) % MOD97;
    }
    cout << "\n";
  }
}
