#include <iostream>
#include <vector>
#include <cstring>

#define UPPER 10000000

using namespace std;

int main() {
  int *p = new int[UPPER], *sq = new int[UPPER], *is_sum = new int[UPPER];
  memset(p, 0, UPPER * sizeof(int));
  memset(sq, 0, UPPER * sizeof(int));
  memset(is_sum, 0, UPPER * sizeof(int));
  for (long long i = 2; i < UPPER; i++) {
    if (p[i] == 0) {
      if (i != 2 && i % 4 != 1)
        p[i] = 1;
      for (long long j = i * i; j < UPPER; j += i)
        p[j] = 1;
    }
  }

  for (long long i = 0; i * i < UPPER; i++) {
    sq[i * i] = 1;
  }

  for (long long i = 2; i < UPPER; i++) {
    is_sum[i] = is_sum[i - 1];
    if (p[i])
      continue;
    for (long long j = 0; i >= j*j*j*j; j++) {
      if (sq[i - j*j*j*j]) {
        is_sum[i]++;
        break;
      }
    }
  }

  delete[] p;
  delete[] sq;
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    cout << is_sum[n] << "\n";
  }
}
