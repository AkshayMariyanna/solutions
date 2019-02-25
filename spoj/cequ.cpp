/// https://www.spoj.com/problems/CEQU/
#include <iostream>

using namespace std;
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int g =  gcd(a, b);

        cout << "Case " << i << ": ";
        if (c % g == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}