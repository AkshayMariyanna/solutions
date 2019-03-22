//! https://www.spoj.com/problems/TDPRIMES/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout.tie(NULL);
    int S = 10000;
    int L = 100000000;
    auto primes = vector<int>();
    auto flags = vector<char>(S + 1, true);
    for (int i = 2; i <= S; i++) {
        if (flags[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= S; j += i) {
                flags[j] = false;
            }
        }
    }

    int count = 0;
    for (int k = 0; k * S < L; k++) {
        int start = k * S;
        fill(flags.begin(), flags.end(), true);
        for (auto p: primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                flags[j] = false;
        }
        if (k == 0)
            flags[0] = flags[1] = false;
        for (int i = 0; i < S && start + i < L; i++)
            if (flags[i]) {
                if (count++ % 100 == 0) {
                    cout << start + i << "\n";
                }
            }
    }
}
