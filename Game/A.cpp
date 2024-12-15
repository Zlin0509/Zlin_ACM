//
// Created by Zlin on 2024/12/1.
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

const int N = 2e5 + 20;

int n, m;
vector<vi> a;

int l[N], r[N];

vi in[N], out[N];

struct node {
    int val, id;

    bool operator<(const node &x) const {
        return val > x.val;
    }
};

inline void Zlin() {
    cin >> n >> m;
    a.assign(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= m; i++) l[i] = 1, r[i] = N;
    vi have;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] != -1) have.push_back(a[i][j]);
        }
        sort(have.begin(), have.end());
        have.erase(unique(have.begin(), have.end()), have.end());
        for (int j = 1; j <= m; j++)
            if (a[i][j] != -1) {
                int x = lower_bound(have.begin(), have.end(), a[i][j]) - have.begin() + 1;
                l[j] = max(l[j], x);
                r[j] = min(r[j], m - (int) have.size() + x);
            }
        have.clear();
    }
    for (int j = 1; j <= m; j++) {
        in[l[j]].push_back(j);
        out[r[j]].push_back(j);
    }
    vi ans;
    set<int> now;
    priority_queue<node> q;
    for (int i = 1; i <= m; i++) {
        for (auto id: in[i]) q.push({r[id], id}), now.insert(id);
        if (q.empty()) {
            cout << -1 << '\n';
            return;
        }
        ans.push_back(q.top().id);
        now.erase(now.find(q.top().id));
        q.pop();
        for (auto id: out[i])
            if (now.find(id) != now.end()) {
                cout << -1 << '\n';
                return;
            }
    }
    if (!q.empty()) {
        cout << -1 << '\n';
        return;
    }
    for (auto it: ans) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}