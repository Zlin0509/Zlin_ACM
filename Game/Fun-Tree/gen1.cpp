#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
mt19937 rng;

int rnd(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc < 6) {
        cerr << "Usage: ./generator <seed> <T_max>\n";
        return 1;
    }

    int seed = stoi(argv[1]);
    int T_max = stoi(argv[2]);
    int SUM_N = stoi(argv[3]);
    int SUM_M = stoi(argv[4]);
    int SUM_Q = stoi(argv[5]);
    rng.seed(seed);


    int T = rnd(1, T_max);
    cout << T << "\n";

    int used_n = 0, used_m = 0, used_q = 0;

    for (int t = 1; t <= T; t++) {
        int n_limit = SUM_N - used_n;
        int m_limit = SUM_M - used_m;
        int q_limit = SUM_Q - used_q;

        if (n_limit <= 0 || m_limit <= 0 || q_limit <= 0) break;

        int n = rnd(1, min(10000, n_limit));
        int max_edges = n * (n - 1) / 2;
        int m = rnd(1, min({m_limit, max_edges, 500000}));
        int q = rnd(1, min(q_limit, 10000));

        used_n += n;
        used_m += m;
        used_q += q;

        cout << n << " " << m << " " << q << "\n";

        // 生成无重边无自环图
        set<pii> edges;
        while ((int) edges.size() < m) {
            int u = rnd(1, n);
            int v = rnd(1, n);
            if (u == v) continue;
            if (u > v) swap(u, v);
            if (!edges.count({u, v})) {
                edges.insert({u, v});
                cout << u << " " << v << "\n";
            }
        }

        // 生成查询 u != v
        for (int i = 0; i < q; i++) {
            int u, v;
            do {
                u = rnd(1, n);
                v = rnd(1, n);
            } while (u == v);
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}
