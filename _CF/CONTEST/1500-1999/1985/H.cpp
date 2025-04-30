//
// Created by Zlin on 2024/9/25.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;

int n, m;
int xl, xr, yl, yr, siz;
vi sumx, sumy, fx, fy;
vector<vector<int>> a, fc, sum, vis;

inline void dfs(int x, int y) {
    if (x > n || x < 1 || y > m || y < 1 || vis[x][y] || !a[x][y]) return;
    ++siz;
    vis[x][y] = 1;
    xl = min(xl, x);
    xr = max(xr, x);
    yl = min(yl, y);
    yr = max(yr, y);
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

inline void Zlin() {
    cin >> n >> m;
    vis.assign(n + 2, vector<int>(m + 2, 0));
    a.assign(n + 2, vector<int>(m + 2, 0));
    fc.assign(n + 2, vector<int>(m + 2, 0));
    sum.assign(n + 2, vector<int>(m + 2, 0));
    sumx.assign(n + 2, 0);
    sumy.assign(m + 2, 0);
    fx.assign(n + 2, 0);
    fy.assign(m + 2, 0);
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            } else {
                ++fx[i];
                ++fy[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fc[i][j] = fx[i] + fy[j];
            if (!a[i][j]) --fc[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] || !a[i][j]) continue;
            xl = xr = i;
            yl = yr = j;
            siz = 0;
            dfs(i, j);
            xl = max(xl - 1, 1);
            xr = min(xr + 1, n);
            yl = max(yl - 1, 1);
            yr = min(yr + 1, m);

//            cout << xl << ' ' << xr << '\n';
//            cout << yl << ' ' << yr << '\n';

            sumx[xl] += siz;
            sumx[xr + 1] -= siz;
            sumy[yl] += siz;
            sumy[yr + 1] -= siz;

            sum[xl][yl] += siz;
            sum[xr + 1][yr + 1] += siz;
            sum[xr + 1][yl] -= siz;
            sum[xl][yr + 1] -= siz;
        }
    }
    for (int i = 1; i <= n; i++)
        sumx[i] += sumx[i - 1];
    for (int i = 1; i <= m; i++)
        sumy[i] += sumy[i - 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << sum[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, fc[i][j] + sumx[i] + sumy[j] - sum[i][j]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}