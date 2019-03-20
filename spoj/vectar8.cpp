#include <iostream>
#include <cstring>

using namespace std;

#define UPPER 1000000

int main() {
  int *p = new int[UPPER], *sum = new int[UPPER];
  memset(p, 1, UPPER * sizeof(int));
  memset(sum, 0, UPPER * sizeof(int));
  int ten = 1;
  p[1] = 0;
  for (long i = 2; i < UPPER; i++) {
    sum[i] = sum[i- 1];
    if (i == ten * 10) {
      ten *= 10;
    }
    if (p[i]) {
      for (long j = i * i; j < UPPER; j += i)
        p[j] = 0;
      int rest = i % ten;
      if (rest < (ten / 10)|| p[rest] == 0)
        p[i] = 0;
      if (p[i])
        sum[i]++;
    }
  }

  delete[] p;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << sum[n] << "\n";
  }
}
