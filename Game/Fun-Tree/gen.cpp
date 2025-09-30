#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int seed = stoi(argv[1]);
    rng.seed(seed);

    // ========== 参数配置 ==========
    int n = 100000; // 最大点数
    int m = 100000; // 最大边数
    int q = 100000; // 最大询问数

    cout << n << " " << m << "\n";

    // ========== 生成额外随机边 ==========
    for (int i = 1; i <= n; i++) cout << i << ' ' << (i + 1 > n ? 1 : i + 1) << '\n';

    cout << q << '\n';

    // ========== 生成 q 个随机询问 ==========
    for (int i = 0; i < q; i++) {
        int u = Rand(1, n);
        int v = Rand(1, n);
        while (u == v) v = Rand(1, n); // 保证 u != v
        cout << u << " " << v << "\n";
    }

    return 0;
}
