//! https://www.spoj.com/problems/NGIRL/

#include <iostream>
#include <cmath>

#define UPPER 100000

using namespace std;
typedef long long ll;

int main() {
  int pr[UPPER + 1] = {0};
  for (ll i = 2; i <= UPPER; i++) {
    if (pr[i] == 0) {
      pr[i] = pr[i - 1] + 1;
    } else {
      pr[i] = pr[i - 1];
    }

    for (ll j = i * i; j <= UPPER; j+=i) {
      pr[j] = 1;
    }
  }

  int T;
  cin >> T;
  while (T--) {
    ll N, K;
    cin >> N >> K;
    N = sqrt(N);
    K = sqrt(K);

    int choices = pr[N];
    int real_choices = N > K ? pr[N] - pr[K] : 0;

    cout << choices << " " << real_choices << "\n";
  }
}
