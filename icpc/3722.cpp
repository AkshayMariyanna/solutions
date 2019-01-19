#include <iostream>

using namespace std;

bool read_input(long long &x, long long &a, long long &n, long long &c) {
  cin >> x >> a >> n >> c;

  return x != 0;
}

struct ExpHolder {
public:
  long long exp;
  long long gp;
};

const struct ExpHolder binomial_exp(long long a, long long n, long long c) {
  a = a%c;
  long long exp = 1;
  long long gp = 0;
  long long gp2 = a;
  while (n) {
    if (n&1) {
      exp = (exp * a) % c;
    }
    if (n&1) {
      gp = (gp2 + (a * gp) % c)%c;
    }
    gp2 = (gp2 + (gp2 * a)%c)%c;
    a = (a*a)%c;
    n >>= 1;
  }

  struct ExpHolder ret;
  ret.exp = exp;
  ret.gp = gp;
  return ret;
}

int main() {
  long long x, a, n, c;

  while (read_input(x, a, n, c)) {
    auto exp_n_gp = binomial_exp(a, n, c);

    cout << ((((x%c) * exp_n_gp.exp)%c) - exp_n_gp.gp + c)%c << "\n";
  }

  return 0;
}
