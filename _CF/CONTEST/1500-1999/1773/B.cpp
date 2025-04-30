//
// Created by 27682 on 2025/4/23.
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

constexpr int N = 1010;
const ull mask = mt19937_64(time(nullptr))();

inline ull shift(ull x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

int n, k, f[N];
vector<vi> a;

inline void dfs(const vector<vi> dat, int fa) {
    int m = dat[0].size();
    if (m == 1) {
        f[dat[0][0]] = fa;
        return;
    }
    vector ha(k, vector<ull>(m));
    for (int i = 0; i < k; i++) {
        ha[i][0] = shift(dat[i][0]);
        for (int j = 1; j < m; j++) ha[i][j] = shift(dat[i][j]) + ha[i][j - 1];
    }
    vector<vector<pair<ull, ull> > > have(n + 1);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            ull lx = ha[i][j], rx = ha[i][m - 1] - (j ? ha[i][j - 1] : 0);
            have[dat[i][j]].push_back({min(lx, rx), max(lx, rx)});
        }
    }
    int tag = -1;
    for (int i = 1; i < m - 1; i++) {
        int it = dat[0][i];
        sort(have[it].begin(), have[it].end());
        have[it].erase(unique(have[it].begin(), have[it].end()), have[it].end());
        if (have[it].size() == 1) {
            tag = it;
            break;
        }
    }
    f[tag] = fa;
    vector<vi> ldat, rdat;
    for (int i = 0, id = 0; i < k; i++) {
        vi lxdat, rxdat;
        for (int j = 0; j < m; j++) {
            if (dat[i][j] == tag) {
                id = j;
                break;
            }
        }
        for (int j = 0; j < id; j++) lxdat.push_back(dat[i][j]);
        for (int j = id + 1; j < m; j++) rxdat.push_back(dat[i][j]);
        if (ha[i][id] == have[tag][0].first) {
            ldat.push_back(lxdat);
            rdat.push_back(rxdat);
        } else {
            rdat.push_back(lxdat);
            ldat.push_back(rxdat);
        }
    }
    dfs(ldat, tag);
    dfs(rdat, tag);
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        vi now(n);
        for (int j = 0; j < n; j++) cin >> now[j];
        a.push_back(now);
    }
    dfs(a, -1);
    for (int i = 1; i <= n; i++) cout << f[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
