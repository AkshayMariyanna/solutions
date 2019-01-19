/// https://www.codechef.com/problems/FLOW016
#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        ll g = gcd(a, b);
        ll l = (a/g) * b;
        
        cout << g << " " << l << "\n";
    }
	// your code goes here
	return 0;
}
