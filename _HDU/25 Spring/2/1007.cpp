//
// Created by Zlin on 2025/3/17.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int mo = 1e9 + 7;

int n, m, k, val;
char a[101][101];
int dx[2] = {0, 1}, dy[2] = {1, 0};
int f[101][20][21][20], g[101][20][21][20];

inline void Zlin()
{
    auto check = [&](int i, int j)
    {
        return i >= 1 && i <= n && j >= 1 && j <= m;
    };
    auto check1 = [&](int i, int j)
    {
        return a[i][j] >= '0' && a[i][j] <= '9';
    };

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int y = 1; y <= m; y++)
        for (int sum = 0; sum < k; sum++)
            for (int mul = 0; mul <= k; mul++)
                for (int val = 0; val < k; val++)
                    f[y][sum][mul][val] = 0, g[y][sum][mul][val] = 0;
    f[1][0][k + 1][(a[1][1] - '0') % k] = 1;

    int ss, mm, nn;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            for (int z = 0; z < 2; z++)
            {
                int xx = x + dx[z];
                int yy = y + dy[z];
                if (!check(xx, yy) || (!check1(x, y) && !check1(xx, yy)))
                    continue;
                if (a[xx][yy] == '+')
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul <= k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                ss = (sum + (mul - 1) * now) % k;
                                mm = 1;
                                nn = 0;
                                if (xx != x)
                                    g[y][ss][mm][nn] = (g[y][ss][mm][nn] + f[y][sum][mul][now]) % mo;
                                else
                                    f[y + 1][ss][mm][nn] = (f[y + 1][ss][mm][nn] + f[y][sum][mul][now]) % mo;
                            }
                }
                else if (a[xx][yy] == '-')
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul <= k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                ss = (sum + (mul - 1) * now) % k;
                                mm = 0;
                                nn = 0;
                                if (xx != x)
                                    g[y][ss][mm][nn] = (g[y][ss][mm][nn] + f[y][sum][mul][now]) % mo;
                                else
                                    f[y + 1][ss][mm][nn] = (f[y + 1][ss][mm][nn] + f[y][sum][mul][now]) % mo;
                            }
                }
                else if (a[xx][yy] == '*')
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul < 2 * k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                ss = sum;
                                mm = (mul - k) * now % k + k;
                                nn = 0;
                                if (xx != x)
                                    g[y][ss][mm][nn] = (g[y][ss][mm][nn] + f[y][sum][mul][now]) % mo;
                                else
                                    f[y + 1][ss][mm][nn] = (f[y + 1][ss][mm][nn] + f[y][sum][mul][now]) % mo;
                            }
                }
                else
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul < 2 * k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                if (xx != x)
                                {
                                    val = (now * 10 + (a[xx][yy] - '0')) % k;
                                    g[y][sum][mul][val] = (g[y][sum][mul][val] + f[y][sum][mul][now]) % mo;
                                }
                                else
                                {
                                    val = (now * 10 + (a[xx][yy] - '0')) % k;
                                    f[y + 1][sum][mul][val] = (f[y + 1][sum][mul][val] + f[y][sum][mul][now]) % mo;
                                }
                            }
                }
            }
        }
        if (x == n)
            continue;
        for (int y = 1; y <= m; y++)
            for (int sum = 0; sum < k; sum++)
                for (int mul = 0; mul < 2 * k; mul++)
                    for (int val = 0; val < k; val++)
                        f[y][sum][mul][val] = g[y][sum][mul][val], g[y][sum][mul][val] = 0;
    }
    ll ans = 0;
    for (int sum = 0; sum < k; sum++)
        for (int mul = 0; mul <= 2 * k; mul++)
            for (int now = 0; now < k; now++)
            {
                val = (sum + (mul - k) * now) % k;
                if (!val) ans = (ans + f[m][sum][mul][now]) % mo;
            }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
