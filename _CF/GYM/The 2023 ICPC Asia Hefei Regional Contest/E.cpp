//
// Created by Zlin on 2024/10/19.
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

const int N = 1e6 + 5;
vi x[N], y[N];
int a[1010][1010];
map<int, int> used, idx;
vi have;

inline void Zlin() {
    int n, m;
    cin >> n >> m;

    for (int i = 1, it; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (!used[a[i][j]]) {
                have.push_back(a[i][j]);
                ++used[a[i][j]];
            }
        }

    for (int i = 0; i < have.size(); i++) idx[have[i]] = i + 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1, it; j <= m; j++) {
            it = idx[a[i][j]];
            x[it].push_back(i);
            y[it].push_back(j);
        }

    ll ans = 0, cnt, sum;
    for (int i: have) {
        int it = idx[i];
        sort(x[it].begin(), x[it].end());
        sort(y[it].begin(), y[it].end());
        cnt = 0, sum = 0;
        for (int j: x[it]) {
            ans += j * cnt - sum;
            cnt++;
            sum += j;
        }
        cnt = 0, sum = 0;
        for (int j: y[it]) {
            ans += j * cnt - sum;
            cnt++;
            sum += j;
        }
    }
    cout << ans * 2ll << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}