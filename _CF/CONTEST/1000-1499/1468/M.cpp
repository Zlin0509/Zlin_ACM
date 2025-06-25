//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 5;

int n, tag[N];
vi a[N], idx, son[N];

vector<ll> have;

inline void Zlin() {
    idx.clear();
    have.clear();
    cin >> n;
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        a[i].assign(k, 0);
        for (int &it: a[i]) {
            cin >> it;
            idx.push_back(it);
        }
        tag[i] = 0;
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    for (int i = 0; i < idx.size(); i++) son[i].clear();
    for (int i = 1; i <= n; i++) {
        for (int &it: a[i]) {
            it = lower_bound(idx.begin(), idx.end(), it) - idx.begin();
            son[it].push_back(i);
        }
    }
    vi l, r;
    for (int i = 0, z = sqrt(n); i < idx.size(); i++) {
        sort(son[i].begin(), son[i].end());
        if (son[i].size() < z) {
            l.push_back(i);
        } else {
            r.push_back(i);
        }
    }

    for (int id: l) {
        for (int i = 0; i < son[id].size(); i++) {
            for (int j = i + 1; j < son[id].size(); j++) {
                int x = son[id][i], y = son[id][j];
                if (x > y) swap(x, y);
                have.push_back(1ll * y * N + x);
            }
        }
    }
    sort(have.begin(), have.end());
    for (int i = 0; i + 1 < have.size(); i++) {
        if (have[i] == have[i + 1]) {
            cout << have[i] / N << ' ' << have[i] % N << endl;
            return;
        }
    }

    for (int id: r) {
        for (int i: son[id]) tag[i] = 1;
        for (int i = 0; i < idx.size(); i++) {
            if (i == id) continue;
            int now = 0;
            for (int j: son[i]) {
                if (tag[j]) {
                    if (!now) now = j;
                    else {
                        cout << now << ' ' << j << endl;
                        return;
                    }
                }
            }
        }
        for (int i: son[id]) tag[i] = 0;
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
