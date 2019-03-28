//! https://www.spoj.com/problems/PON/
/// PON without looking

#include <iostream>

using namespace std;

typedef unsigned __int128 u128;
typedef unsigned long long ll;

ll binomial_exponentiation(ll x, ll n, ll mod) {
  x = x % mod;
  ll result = 1;

  while (n) {
    if (n & 1)
      result = ((u128)x * result) % mod;
    n >>= 1;
    x = ((u128)x * x) % mod;
  }

  return result;
}

bool is_composite(ll n, ll a, ll d, ll s) {
  ll x = binomial_exponentiation(a, d, n);
  if (x == 1 || x == n - 1)
    return false;

  for (ll r = 1; r < s; r++) {
    x = ((u128) x * x) % n;
    if (x == n - 1)
      return false;
  }

  return true;
}

bool isPrime(ll n) {
  if (n < 2)
    return false;

  ll d = n - 1;
  ll s = 0;
  while ((d & 1) == 0) {
    s++;
    d >>= 1;
  }

  for (ll a : {2,3,5,7,11,13,17,19,23,29,31,37}) {
    if (n == a)
      return true;
    if (is_composite(n, a, d, s))
      return false;
  }

  return true;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    ll N;
    cin >> N;

    if (isPrime(N)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
