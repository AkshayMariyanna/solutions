#include <iostream>
#include <cstring>

using namespace std;

int main() {
  using ll = long long;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int * prim_x = new int[100000001];
  int * prim_y = new int[100000001];
  memset(prim_x, 1, sizeof(int) * 100000001);
  prim_x[0] = prim_x[1] = 0;
  int row = 1;
  int column = 0;
  for (ll i = 2; i <= 100000000; i++) {
    if (prim_x[i]) {
      if (column == row) {
        column = 0;
        row++;
      }
      prim_x[i] = row;
      prim_y[i] = ++column;
      for (ll j = i * i; j <= 100000000; j+=i) {
        prim_x[j] = 0;
      }
    }
  }

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;

    if (prim_x[n]) {
      cout << prim_x[n] << " " << prim_y[n] << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
