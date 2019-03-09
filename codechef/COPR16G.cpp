#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (a != 0) {
        ll y = a;
        a = b % a;
        b = y;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a>> b;
        if (gcd(a, b) != 1) {
            cout << "-1\n";
        } else {
            cout << a*b - a- b + 1 << "\n";
        }
    }
	// your code goes here
	return 0;
}

