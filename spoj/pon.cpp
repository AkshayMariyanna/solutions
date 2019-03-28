//! https://www.spoj.com/problems/PON/
/// PON with cp-algo reference
#include <iostream>

using namespace std;

typedef unsigned __int128 uint128;
typedef unsigned long long ll;

ll binpower(ll x, ll n, ll mod) {
  ll ans = 1;
  x %= mod;

  while (n) {
    if (n & 1)
      ans = ((uint128) ans * x) % mod;
    x = ((uint128) x * x) % mod;
    n >>= 1;
  }

  return ans;
}

bool check_composite(ll n, ll a, ll d, ll s) {
  ll x = binpower(a, d, n);
  if (x == 1 || x == n - 1)
    return false;

  for (ll r = 1; r < s; r++) {
    x = ((uint128)x * x) % n;
    if (x == n - 1)
      return false;
  }

  return true;
}

bool isPrime(ll n) {
  if (n < 2)
    return false;

  int r = 0;
  ll d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a)
      return true;
    if (check_composite(n, a, d, r))
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

    if (isPrime(N))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
