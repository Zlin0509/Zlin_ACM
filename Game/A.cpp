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

const int N = 1e6 + 10;


inline void Zlin() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vi a(N), ans(N), b(N), c(N);
    unordered_map<int, int> used, num;
    for (int i = 1, x; i <= n; i++) {
        cin >> b[i];
        if (!used[b[i]]) {
            used[b[i]] = 1;
            a[cnt++] = b[i];
        }
        ++num[b[i]];
    }
    for (int i = 0; i < cnt; i++) c[i] = num[a[i]];
    for (int i = 0; i < cnt; i++)
        for (int j = 1; a[i] * j <= m; j++)
            ans[a[i] * j] += c[i];
//    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (ans[res] < ans[i])
            res = i;
    if (!ans[res]) {
        cout << "1 0" << '\n';
        return;
    }
    cout << res << ' ' << ans[res] << '\n';
    for (int i = 1; i <= n; i++) if (res % b[i] == 0) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}