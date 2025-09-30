#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main() {
    // int seed = stoi(argv[1]);
    // rng.seed(seed);

    int n = 100000; // 最大点数
    int m = 1000; // 最大边数
    int q = 1000; // 最大询问数

    cout << n << " " << m << " " << q << "\n";

    for (int i = 1; i <= m; i++) cout << i << ' ' << (i + 1 > n ? 1 : i + 1) << '\n';

    for (int i = 0; i < q; i++) {
        int u = Rand(1, n);
        int v = Rand(1, n);
        while (u == v) v = Rand(1, n); // 保证 u != v
        cout << u << " " << v << "\n";
    }

    cout << endl;

    return 0;
}
