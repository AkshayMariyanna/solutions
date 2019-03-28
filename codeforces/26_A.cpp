//! https://codeforces.com/contest/26/problem/A

#include <iostream>
#include <vector>

#define UPPER 3000

using namespace std;

int main() {
  int pr[UPPER + 1] = {0};
  int sum[UPPER + 1] = {0};
  vector<int> primes;

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (pr[i] == 0) {
      pr[i] = i;
      primes.push_back(i);
    } else {
      int k = i;
      int other = 0;
      while (pr[k] != k) {
        if (pr[k] != pr[i]) {
          if (other && other != pr[k]) {
            break;
          } else {
            other = pr[k];
          }
        }
        k = k/pr[k];
      }
      if ((other == 0 || other == pr[k]) && k != pr[i]) {
        sum[i]++;
      }
    }
    int size = primes.size();
    for (int j = 0; j < size && i * primes[j] <= n && primes[j] <= pr[i]; j++)
      pr[i * primes[j]] = primes[j];
  }

  cout << sum[n] << "\n";
}
