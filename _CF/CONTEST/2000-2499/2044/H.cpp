//
// Created by 27682 on 2025/3/3.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vector a(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    vector sum(n + 1, vll(n + 1, 0));
    vector sumx(n + 1, vll(n + 1, 0));
    vector sumy(n + 1, vll(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            sumx[i][j] = a[i][j] * i + sumx[i - 1][j] + sumx[i][j - 1] - sumx[i - 1][j - 1];
            sumy[i][j] = a[i][j] * j + sumy[i - 1][j] + sumy[i][j - 1] - sumy[i - 1][j - 1];
        }
    while (q--) {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        ll ans = (1 - ya - xa * yb + xa * ya - xa) *
                 (sum[xb][yb] - sum[xa - 1][yb] - sum[xb][ya - 1] + sum[xa - 1][ya - 1]) +
                 (yb - ya + 1) * (sumx[xb][yb] - sumx[xa - 1][yb] - sumx[xb][ya - 1] + sumx[xa - 1][ya - 1]) +
                 sumy[xb][yb] - sumy[xa - 1][yb] - sumy[xb][ya - 1] + sumy[xa - 1][ya - 1];
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}