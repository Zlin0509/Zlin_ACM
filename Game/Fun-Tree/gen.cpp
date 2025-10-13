#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 1e5;

set<pii> st;

int main() {
    int n, m, q;
    n = 1000;
    m = q = N;
    cout << n << ' ' << m << ' ' << q << "\n";
    // for (int i = 1; i < n; i++) {
    //     cout << i << ' ' << i + 1 << endl;
    //     m--;
    //     st.insert({i, i + 1});
    //     st.insert({i + 1, i});
    // }
    while (m--) {
        int x, y;
        do {
            x = rng() % n + 1;
            y = rng() % n + 1;
        } while (x == y || st.count({x, y}));
        st.insert({x, y});
        st.insert({y, x});
        cout << x << ' ' << y << "\n";
    }
    while (q--) {
        int x = rng() % n + 1;
        int y = (x + 1) % n + 1;
        cout << x << ' ' << y << "\n";
    }
}
