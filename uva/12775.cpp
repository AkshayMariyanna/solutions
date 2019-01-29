//! https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628
#include <iostream>

using namespace std;

typedef long long ll;

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

void shift_solution(ll ag, ll bg, ll offset, ll &x, ll &y) {
  x += bg * offset;
  y -= ag * offset;
}

ll find_all_solutions(ll a, ll b, ll d, ll g, ll x, ll y) {
  if (d % g) return 0;
  ll xmin = 0;
  ll xmax = d / a;
  ll ymin = 0;
  ll ymax = d / b;

  ll mult = d / g;
  x *= mult;
  y *= mult;

  a = a / g;
  b = b / g;

  shift_solution(a, b, (xmin - x) / b, x, y);
  if (x < xmin)
    shift_solution(a, b, 1, x, y);
  if (x > xmax)
    return 0;
  ll lx1 = x;

  shift_solution(a, b, (xmax - x) / b, x, y);
  if (x > xmax)
    shift_solution(a, b, -1, x, y);
  ll rx1 = x;

  shift_solution(a, b, -(ymin - y) / a, x, y);
  if (y < ymin)
    shift_solution(a, b, -1, x, y);
  if (y > ymax)
    return 0;
  ll lx2 = x;

  shift_solution(a, b, -(ymax - y), x, y);
  if (y > ymax)
    shift_solution(a, b, 1, x, y);
  ll rx2 = x;

  if (lx2 > rx2) {
    ll temp = lx2;
    lx2 = rx2;
    rx2 = temp;
  }

  ll lx = lx1 > lx2 ? lx1 : lx2;
  ll rx = rx1 < rx2 ? rx1 : rx2;

  return lx > rx ? 0 : (rx - lx) / b + 1;
}

ll count_sols(ll a, ll b, ll c, ll p) {
  ll x0, y0;
  ll g = gcd(a, b, x0, y0);

  ll x, y;
  ll g1 = gcd(g, c, x, y);

  ll x1, y1;
  ll g2 = gcd(c, b, x1, y1);
  ll x2, y2;
  ll g3 = gcd(c, a, x2, y2);
  ll res = 0;

  if (p % g1) {
    return res;
  }

  ll z = 0;
  while (z <= p) {
    ll d = p - z;
    if (d < a && d < b) {
      if (p % c == 0) {
        res++;
      }
      break;
    } else if (d % g != 0) {
      // Nothing to do
    } else if (d < b){
      res += find_all_solutions(c, a, d, g3, x2, y2);
      break;
    } else if (d < a) {
      res += find_all_solutions(c, b, d, g2, x1, y1);
      break;
    }else {
      res += find_all_solutions(a, b, d, g, x0, y0);
    }

    z += c;
  }

  return res;
}

int main() {
  ll T;
  cin >> T;

  for(ll i = 1; i <= T; i++) {
    ll a, b, c, p;
    cin >> a >> b >> c >> p;

    if (a > b) {
      ll temp = b;
      b = a;
      a = temp;
    }
    if (b > c) {
      ll temp = c;
      c = b;
      b = temp;
    }
    cout << "Case " << i << ": " << count_sols(a, b, c, p) << "\n";
  }

  return 0;
}
