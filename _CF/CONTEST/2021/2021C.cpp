//
// Created by Zlin on 2024/10/21.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 10;
int a[N], b[N], tag[N];
int n, m, q, cnt;
unordered_map<int, int> idx;
set<int> place[N];
multiset<int, greater<int>> have;

void check(int x, int siz) {
    if (place[x].empty() || !x || x > siz) {
        if (tag[x]) --cnt;
        tag[x] = 0;
        return;
    }
    if (x == siz) {
        if (!tag[x]) ++cnt, tag[x] = 1;
    } else {
        if (!place[x + 1].empty() && *place[x + 1].begin() < *place[x].begin()) {
            if (tag[x]) --cnt, tag[x] = 0;
        } else {
            if (!tag[x]) ++cnt, tag[x] = 1;
        }
    }
}

inline void Zlin() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) idx[a[i]] = i;
    for (int i = 1; i <= m; i++) {
        b[i] = idx[b[i]];
        place[b[i]].insert(i);
    }
    cnt = 0;
    for (int i = 1; i <= m; i++) {
        have.insert(b[i]);
        check(b[i], *have.begin());
        check(b[i], *have.begin());
    }
    cout << (cnt == *have.begin() ? "YA" : "TIDAK") << '\n';
    int s, t;
    while (q--) {
        cin >> s >> t;
        t = idx[t];
        have.erase(have.find(b[s]));
        place[b[s]].erase(place[b[s]].find(s));
        check(b[s], *have.begin());
        check(b[s] - 1, *have.begin());
        check(b[s] + 1, *have.begin());
        b[s] = t;
        have.insert(b[s]);
        place[b[s]].insert(s);
        check(b[s], *have.begin());
        check(b[s] - 1, *have.begin());
        check(b[s] + 1, *have.begin());
        cout << (cnt == *have.begin() ? "YA" : "TIDAK") << '\n';
    }

    have.clear();
    idx.clear();
    for (int i = 1; i <= n; i++) {
        tag[i] = 0;
        place[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}