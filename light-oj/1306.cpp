#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void gcd(ll a, ll b, ll & x, ll & y, ll & g) {
  if (a == 0) {
    x = 0;
    y = 1;
    g = b;
  } else {
    ll x1, y1;
    gcd(b % a, a, x1, y1, g);

    x = y1 - (b / a) * x1;
    y = x1;
  }
}

ll get_sign(ll i) {
  return i < 0 ? -1 : 1;
}

bool find_one(ll a, ll b, ll c, ll & x, ll & y, ll & g) {
  gcd(abs(a), abs(b), x, y, g);
  if (c % g != 0)
    return false;

  ll mult = c / g;
  x *= get_sign(a) * mult;
  y *= get_sign(b) * mult;

  return true;
}

void shift_solution(ll & x, ll & y, ll ag, ll bg, ll offset) {
  x += offset * bg;
  y -= offset * ag;
}

ll find_count(ll a, ll b, ll c, ll x1, ll x2, ll y1, ll y2) {
  ll x, y, g;
  if (!find_one(a, b, c, x, y, g))
    return 0;

  ll sign_a = get_sign(a);
  ll sign_b = get_sign(b);

  a = a / g;
  b = b / g;

  shift_solution(x, y, a, b, (x1 - x) / b);
  if (x < x1)
    shift_solution(x, y, a, b, sign_b);
  if (x > x2)
    return 0;
  ll lx1 = x;

  shift_solution(x, y, a, b, (x2 - x) / b);
  if (x > x2)
    shift_solution(x, y, a, b, -sign_b);
  ll rx1 = x;

  shift_solution(x, y, a, b, (y - y1) / a);
  if (y < y1)
    shift_solution(x, y, a, b, -sign_a);
  if (y > y2)
    return 0;
  ll lx2 = x;

  shift_solution(x, y, a, b, (y - y2) / a);
  if (y > y2)
    shift_solution(x, y, a, b, sign_a);
  ll rx2 = x;

  if (lx2 > rx2) {
    ll temp = lx2;
    lx2 = rx2;
    rx2 = temp;
  }

  ll lx = lx1 > lx2 ? lx1 : lx2;
  ll rx = rx1 < rx2 ? rx1 : rx2;

  if (lx > rx) return 0;

  return (rx - lx) / abs(b) + 1;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  //cout.tie(NULL);

  ll T;
  cin >> T;

  for (ll i = 1; i <= T; i++) {
    cout << "Case " << i << ": ";
    ll a, b, c, x1, x2, y1, y2, ans;

    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

    c = -c;
    if (a == 0 && b == 0 && c == 0) {
      ans = (y2 - y1 + 1) * (x2 - x1 + 1);
    } else if (a == 0 && b == 0) {
      ans = 0;
    } else if (a == 0 && (c / b) >= y1 && (c / b) <= y2) {
      ans = x2 - x1 + 1;
    } else if (b == 0 && (c / a) >= x1 && (c / a) <= x2) {
      ans = y2 - y1 + 1;
    } else if (a == 0 || b == 0) {
      ans = 0;
    } else if (x1 > x2 || y1 > y2) {
      ans = 0;
    } else {
      ans = find_count(a, b, c, x1, x2, y1, y2);
    }

    cout << ans << endl;
  }

  return 0;
}
