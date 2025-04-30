//
// Created by 27682 on 2025/4/18.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    int a, b, val;

    bool operator<(const node &x) const {
        return val > x.val;
    }
};

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vector<node> a(m);
    vi lst(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i].a >> a[i].b >> a[i].val;
        a[i].a--, a[i].b--;
    }
    sort(a.begin(), a.end());
    vector<vi> have(n);
    for (int i = m - 1; ~i; i--) {
        have[a[i].a].push_back(a[i].val);
        have[a[i].b].push_back(a[i].val);
    }
    vi used(n);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        have[a[i].a].pop_back();
        have[a[i].b].pop_back();
        if (!used[a[i].a] && !used[a[i].b]) {
            int l = have[a[i].a].size() - 1, r = have[a[i].b].size() - 1;
            while (~l && ~r && have[a[i].a][l] == have[a[i].b][r]) --l, --r;
            if (l == -1 && r == -1) {
                used[a[i].a] = 1;
            } else if (l < r) {
                used[a[i].a] = 1;
            } else {
                used[a[i].b] = 1;
            }
            ans += a[i].val;
        } else if (!used[a[i].a]) {
            used[a[i].a] = 1;
            ans += a[i].val;
        } else if (!used[a[i].b]) {
            used[a[i].b] = 1;
            ans += a[i].val;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
