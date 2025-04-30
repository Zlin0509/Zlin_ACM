//
// Created by Zlin on 2025/1/18.
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

constexpr int N = 310;

ll dis[N][N];
int n, k;

inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dis[i][j];

    cin >> k;
    while (k--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (dis[u][v] > w)
        {
            dis[u][v] = dis[v][u] = w;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j) continue;
                    dis[i][j] = min(dis[i][j], dis[i][u] + dis[u][j]);
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j) continue;
                    dis[i][j] = min(dis[i][j], dis[i][v] + dis[v][j]);
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans += dis[i][j];
        cout << ans / 2 << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
