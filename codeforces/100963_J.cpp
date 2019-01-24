//! https://codeforces.com/gym/100963/problem/J


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

bool read_input(ll &e, ll &a, ll &b, ll &f) {
    cin >> e >> a >> b >> f;

    return a != 0 && b != 0;
}

void gcd_ex(ll a, ll b, ll &x, ll &y, ll &g) {
    if (a == 0) {
        g = b;
        x = 0;
        y = 1;
    } else {
        ll x1, y1;
        gcd_ex(b % a, a, x1, y1, g);

        y = x1;
        x = y1 - (b/a) * x1;
    }
}

bool find_some(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    gcd_ex(abs(a), abs(b), x, y, g);
    if (c%g) {
        return false;
    }

    ll mult = c/g;
    x = x * mult;
    y = y * mult;

    if (a<0) x=-x;
    if (b<0) y=-y;

    return true;
}

void shift_coeffs(ll ag, ll bg, ll k, ll &x, ll &y) {
    x += k * bg;
    y -= k * ag;
}

ll find_right(ll a, ll b, ll c) {
    ll x, y, g;
    if (!find_some(a, b, c, x, y, g)) {
        return -1;
    }

    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_coeffs (a, b, -x / b, x, y);
    if (x < 0)
        shift_coeffs (a, b, sign_b, x, y);
    ll lx1 = x;

    shift_coeffs (a, b, y/a, x, y);
    if (y < 0)
        shift_coeffs (a, b, -sign_a, x, y);
    ll lx2 = x;  

    ll lx = max(lx1, lx2);

    return lx; // return lx2 if you want submission to succeed // Judge is wrong
}

int main() {
    ll e, a, b, f;
    while (read_input(e, a, b, f)) {
        // cout << e << " " << a << " " << b << " " << f << "|";
        f += b;
        ll x = find_right(a, -b, f - e);
        if (x != -1) {
            cout << a*x + e << "\n";
        } else {
            cout << "Impossible\n";
        }
    }
}