#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void shift_solution (int & x, int & y, int a, int b, int cnt) {
  x += cnt * b;
  y -= cnt * a;
}

int find_all_solutions (int a1, int b1, int e, int f) {
  int a = a1;
  int b = -b1;
  int c = f - e;
  int x, y, g;

  int m = max(e, f);
  int minx = 0; //ceil(((double)(m - e))/(double)a1);
  int miny = 0; //ceil(((double)(m - f))/(double)b1);

  if (! find_any_solution (a, b, c, x, y, g))
    return 0;
  a /= g;
  b /= g;


  int sign_a = a>0 ? +1 : -1;
  int sign_b = b>0 ? +1 : -1;

  shift_solution (x, y, a, b, (minx - x) / b);
  if (x < minx)
    shift_solution (x, y, a, b, sign_b);
  int lx1 = x;


  shift_solution (x, y, a, b, - (miny - y) / a);
  if (y < miny)
    shift_solution (x, y, a, b, -sign_a);
  int lx2 = x;

  // int lx = max (lx1, lx2);

  return lx1 * a1 + e;
}

bool read_input(int &a, int &b, int &c, int &d) {
  cin >> a >> b >> c >> d;

  return a != 0;
}

int main() {

  int a, b, e, f;
  while (read_input(e, a, f, b)) {
    f += b;

    if (int ans = find_all_solutions(a, b, e, f)) {
      cout << ans << "\n";
    } else {
      cout << "Impossible\n";
    }
  }
  return 0;
}
