#include <bits/stdc++.h>
using namespace std;

int main() {
    // 随机种子（可固定便于复现）
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int T = uniform_int_distribution<int>(1, 200000)(rng);
    cout << T << '\n';
    while (T--) {
        // n ∈ [2, 1e9]
        long long n = uniform_int_distribution<long long>(2, 1000000000)(rng);
        int a1 = uniform_int_distribution<int>(1, 10000)(rng);
        int b1 = uniform_int_distribution<int>(1, 1000000)(rng);
        int a2 = uniform_int_distribution<int>(1, 10000)(rng);
        int b2 = uniform_int_distribution<int>(1, 1000000)(rng);
        cout << n << " " << a1 << " " << b1 << " " << a2 << " " << b2 << '\n';
    }
    return 0;
}
