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

int n, siz[N], tag[N];
vi v[N];
vector<pii> e[N];

inline void Zlin() {
    cin >> n;
    vi idx;
    for (int i = 1; i <= n; i++) {
        cin >> siz[i];
        v[i].assign(siz[i], 0);
        for (int &it: v[i]) {
            cin >> it;
            idx.push_back(it);
        }
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    for (int i = 1; i <= n; i++) for (int &it: v[i]) it = lower_bound(idx.begin(), idx.end(), it) - idx.begin();
    vi l, r;
    for (int i = 1, dif = sqrt(n); i <= n; i++) siz[i] >= dif ? l.push_back(i) : r.push_back(i);

    // 大集合
    for (int i = 0; i < idx.size(); i++) {
        tag[i] = 0;
        e[i].clear();
    }
    for (int id1: l) {
        for (int val: v[id1]) tag[val] = 1;
        for (int id2 = 1, check; id2 <= n; id2++) {
            if (id1 == id2) continue;
            check = 0;
            for (int val: v[id2]) {
                if (tag[val]) {
                    if (check) {
                        cout << id1 << ' ' << id2 << endl;
                        return;
                    }
                    check = 1;
                }
            }
        }
        for (int val: v[id1]) tag[val] = 0;
    }

    // 小集合
    for (int id: r) {
        for (int i = 0; i < siz[id]; i++) {
            for (int j = i + 1; j < siz[id]; j++) {
                int x = v[id][i], y = v[id][j];
                if (x > y) swap(x, y);
                e[x].push_back({y, id});
            }
        }
    }
    for (int i = 0; i < idx.size(); i++) {
        for (pii &j: e[i]) {
            if (tag[j.first]) {
                cout << tag[j.first] << ' ' << j.second << endl;
                return;
            }
            tag[j.first] = j.second;
        }
        for (pii &j: e[i]) tag[j.first] = 0;
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
