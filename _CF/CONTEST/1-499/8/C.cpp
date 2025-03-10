//
// Created by Zlin on 2025/1/13.
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

constexpr int N = 1E9;

int n;
int dis[25][25];
int pre[1 << 24], dp[1 << 24];

struct node
{
    int x, y;
} a[25];

inline void Zlin()
{
    cin >> a[0].x >> a[0].y;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dis[i][j] = dis[j][i] = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
    for (int i = 0; i < 1 << n; i++) dp[i] = N;
    pre[0] = dp[0] = 0;
    for (int now = 0, sub; now < 1 << n; now++)
    {
        if (dp[now] == N) continue;
        for (int i = 1; i <= n; i++)
        {
            if (now & 1 << i - 1) continue;
            for (int j = 1; j <= n; j++)
            {
                if (now & 1 << j - 1) continue;
                sub = now | (1 << i - 1) | (1 << j - 1);
                if (dp[sub] > dp[now] + dis[0][i] + dis[i][j] + dis[j][0])
                {
                    dp[sub] = dp[now] + dis[0][i] + dis[i][j] + dis[j][0];
                    pre[sub] = now;
                }
            }
            break;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    int now = (1 << n) - 1;
    while (now)
    {
        cout << 0 << ' ';
        int tag = now ^ pre[now];
        now = pre[now];
        for (int i = 0; i < n; i++)
            if (tag & 1 << i)
                cout << i + 1 << ' ';
    }
    cout << 0 << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
