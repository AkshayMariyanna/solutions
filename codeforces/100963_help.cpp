#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
// using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;

#define maxn 100010

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

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
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

void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions (ll a, ll b, ll c, ll minx, ll miny) {
    ll x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return -1;
    a /= g;  b /= g;

    ll sign_a = a>0 ? +1 : -1;
    ll sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    ll lx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    ll lx2 = x;

    return lx1; //max(lx1, lx2); // max(lx1, lx2);
}

ll solve1 (ll n, ll m, ll a, ll k) {
    k += a;

    ll a1, b1, c1;
    a1 = a;
    b1 = -m;
    c1 = n - k;

    if (c1 == 0) {
        return k;
        //cout << k << "\n";
        //continue;
    }

    assert (!(a1 == 0 and b1 == 0));

    ll x = find_all_solutions (a1, b1, c1, 0, 0);
    if (x == -1) {
        return -1;
        //cout << "Impossible\n";
    } else {
        // cout << x<<"\n";
        k += a * x;
        return k;
    }
}

ll solve2 (ll c, ll a, ll b, ll d) {
    d += b;
    ll x, y;
    ll g = gcd(a, b, x, y);

    ll diff = d - c;
    if (diff % g != 0) {
        return -1;
        //cout << "Impossible\n";
        //continue;
    }

    ll mult = diff / g; // ax - by = mult * gcd

    ll lcm = (a / g) * b;

    x = x * mult;
    y = -y * mult;

    ll origin = a * x + c; // one of the solutions
    // cout << x << "\n";
    // cout << a << "\n";
    // cout << c << "\n";
    // cout << origin << "\n";
    ll min_bound = max(c, d); // the answer has to be atleast max(c, d)

    ll signed_det = origin - min_bound; // signed distance from the "one of the solutions"
    ll signed_short = signed_det % lcm; // distance from one of the 2 closest solutions

    ll offset = signed_short >= 0 ? signed_short : lcm + signed_short; // distance from actual solution

    ll answer = min_bound + offset; // actual solution

    return answer;
    //cout << answer << "\n";
}


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10;j++) {
            for (int k = 1; k <= 10; k++) {
                for (int m = 1; m <= 10; m++) {
	ll mau = solve1(i, j, k, m);
	ll mak = solve2(i, j, k, m);
                    if (mau != mak) {
                        cout << i << " " << j << " " << k << " " << m << "|" << mau << "|" << mak << "\n";
                    }
                }
            }
        }
    }

    return 0;

}

 
