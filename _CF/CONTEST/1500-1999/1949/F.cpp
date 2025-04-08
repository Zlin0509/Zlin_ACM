//
// Created by 27682 on 2025/4/7.
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

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vector<pair<vi, int> > a;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        vi now(k);
        for (int &it: now) cin >> it, --it;
        a.emplace_back(now, i + 1);
    }
    sort(a.begin(), a.end(), [&](const pair<vi, int> &a, const pair<vi, int> &b) {
        return a.first.size() < b.first.size();
    });
    vi lst(m, -1), vis(n, 0);
    for (int i = 0; i < n; i++) {
        vi s;
        for (int it: a[i].first) {
            if (lst[it] == -1) {
                lst[it] = i;
                continue;
            }
            if (!vis[lst[it]]) s.emplace_back(lst[it]);
            vis[lst[it]]++;
            lst[it] = i;
        }
        for (int it: s) {
            if (vis[it] != a[it].first.size()) {
                cout << "YES" << endl;
                cout << a[i].second << ' ' << a[it].second << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
