//
// Created by Zlin on 2024/9/5.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;

ll n, m, k, len, sum, tag, le;
ll ans[N], z[N];

struct ss {
    ll x, y, id;

    bool operator<(const ss &a) const {
        if (y != a.y)return y < a.y;
        return x > a.x;
    }
};

vector<ss> a;


inline void init() {
    a.clear();
    sum = tag = 0;
    le = 1;
}

inline void Zlin() {
    cin >> n >> m >> k;

    init();

    for (int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        a.push_back({x, y, i});
    }

    sort(a.begin(), a.end());
    for (auto it: a) {
        sum += (n - tag) * (it.y - le);
        le = it.y;
        if (it.x > tag) tag = it.x, ans[it.id] = 1;
        else ans[it.id] = 0;
    }
    sum += (n - tag) * (m - le + 1);
    cout << sum << '\n';
    for (int i = 1; i <= k; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}