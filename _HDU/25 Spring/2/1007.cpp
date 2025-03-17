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
int dp[101][101][20][40][20];
int dx[2] = {0, 1}, dy[2] = {1, 0};

inline void Zlin()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int sum = 0; sum < k; sum++)
                for (int mul = 0; mul <= 2 * k; mul++)
                    for (int now = 0; now < k; now++)
                        dp[i][j][sum][mul][now] = 0;

    auto check = [&](int i, int j)
    {
        return i >= 1 && i <= n && j >= 1 && j <= m;
    };
    auto check1 = [&](int i, int j)
    {
        return a[i][j] >= '0' && a[i][j] <= '9';
    };

    dp[1][1][0][k + 1][(a[1][1] - '0') % k] = 1;
    for (int x = 1; x <= n; x++)
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
                        for (int mul = 0; mul <= 2 * k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                if (!dp[x][y][sum][mul][now])
                                    continue;
                                val = (sum + (mul - k) * now) % k;
                                dp[xx][yy][val][k + 1][0] = (dp[xx][yy][val][k + 1][0] + dp[x][y][sum][mul][now]) % mo;
                            }
                }
                else if (a[xx][yy] == '-')
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul <= 2 * k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                if (!dp[x][y][sum][mul][now])
                                    continue;
                                val = (sum + (mul - k) * now) % k;
                                dp[xx][yy][val][k - 1][0] = (dp[xx][yy][val][k - 1][0] + dp[x][y][sum][mul][now]) % mo;
                            }
                }
                else if (a[xx][yy] == '*')
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul <= 2 * k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                if (!dp[x][y][sum][mul][now])
                                    continue;
                                val = (mul - k) * now % k + k;
                                dp[xx][yy][sum][val][0] = (dp[xx][yy][sum][val][0] + dp[x][y][sum][mul][now]) % mo;
                            }
                }
                else
                {
                    for (int sum = 0; sum < k; sum++)
                        for (int mul = 0; mul <= 2 * k; mul++)
                            for (int now = 0; now < k; now++)
                            {
                                val = (now * 10 + (a[xx][yy] - '0')) % k;
                                dp[xx][yy][sum][mul][val] = (dp[xx][yy][sum][mul][val] + dp[x][y][sum][mul][now]) % mo;
                            }
                }
            }
        }
    ll ans = 0;
    for (int sum = 0; sum < k; sum++)
        for (int mul = 0; mul <= 2 * k; mul++)
            for (int now = 0; now < k; now++)
            {
                if (!dp[n][m][sum][mul][now])
                    continue;
                val = (sum + (mul - k) * now) % k;
                if (!val)
                    ans = (ans + dp[n][m][sum][mul][now]) % mo;
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
