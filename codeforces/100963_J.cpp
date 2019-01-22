#include <iostream>

using namespace std;

typedef long long ll;

bool read_input(ll &x, ll &a, ll &y, ll &b) {
  cin >> x >> a >> y >> b;

  return x != 0;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }

  ll x1, y1;
  ll g = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;

  return g;
}

ll max(ll a, ll b) {
  return a < b ? b : a;
}

int main() {
  ll c, a, d, b;

  while (read_input(c, a, d, b)) {
    d += b;
    ll x, y;
    ll g = gcd(a, b, x, y);

    ll diff = d - c;
    if (diff % g != 0) {
      cout << "Impossible\n";
      continue;
    }

    ll mult = diff / g;

    ll lcm = (a / g) * b;

    x = x * mult;
    y = -y * mult;

    ll origin = a * x + c;
    ll min_bound = max(c, d);

    ll signed_det = origin - min_bound;
    ll signed_short = signed_det % lcm;

    ll offset = signed_short >= 0 ? signed_short : lcm + signed_short;

    ll answer = min_bound + offset;

    cout << answer << "\n";
  }

  return 0;
}
