//! https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd_extended(ll a, ll b, ll &x, ll &y) {
  if (a == 0 && b == 0) {
    x = 0;
    y = 0;
    return 0;
  } else if (a == 0) {
    x = 0;
    y = 1;
    return b;
  } else if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    ll x1, y1;
    ll gcd = gcd_extended(b , a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
  }
}

int main() {
  while (!cin.eof()) {
    ll a = 1000000007, b;
    cin >> a >> b;

    if (a == 1000000007) break;

    ll x, y;
    ll g = gcd_extended(a, b, x, y);

    cout << x << " " << y << " " << g << "\n";
  }

  return 0;
}
