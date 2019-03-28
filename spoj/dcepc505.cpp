//! https://www.spoj.com/problems/DCEPC505/

#include <iostream>
#include <cstring>
#include <vector>

#define S 10600000
using namespace std;

int main() {
  long long * list = new long long[700000];
  long long * pr = new long long[S];
  long long * bazi = new long long[2000000];
  long long count = 0;
  memset(pr, 0, S * sizeof(int));
  int index = 0;
  for (int i = 2; i < S; i++) {
    if (pr[i] == 0) {
      pr[i] = i;
      list[index++] = i;
    } else {
      auto p = i / pr[i];
      if (pr[p] == p && p != pr[i]) {
        bazi[count++] = i;
        if (count == 2000000)
          break;
      }
    }

    for (long long j = 0; i * list[j] < S && j < index && list[j] <= pr[i]; j++) {
      pr[i * list[j]] = list[j];
    }
  }

  int T;
  cin >> T;

  while (T--) {
    int K;
    cin >> K;
    cout << bazi[K - 1] << "\n";
  }
}
