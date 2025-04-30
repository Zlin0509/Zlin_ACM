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

constexpr int N = 410;
constexpr int INF = 1E9;

int h, t, n, m, k, ans;
vi h_n(N), t_n(N), h_m(N), t_m(N);
vi dis(N * N), in(N * N);
vector<vi> G(N * N), E(N * N);
vector<bool> vis(N * N);

int get(int x, int y)
{
    return x * 400 + y;
}

void dijkstra()
{
    fill(vis.begin(), vis.end(), false);
    fill(dis.begin(), dis.end(), INF);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dis[get(h, t)] = 0;
    q.push({0, get(h, t)});

    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (int y : G[x])
        {
            if (dis[y] > dis[x] + 1)
            {
                dis[y] = dis[x] + 1;
                q.push({dis[y], y});
            }
        }
    }
}

int topo_sort()
{
    fill(vis.begin(), vis.end(), false);
    queue<pii> q;

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; i + j <= k; j++)
        {
            int x = get(i, j);
            for (int y : G[x])
            {
                E[y].push_back(x);
                in[x]++;
            }
        }
    }

    q.push({100000, 0});
    while (!q.empty())
    {
        pii tmp = q.front();
        q.pop();
        if (vis[tmp.first]) continue;
        vis[tmp.first] = true;
        if (tmp.first == get(h, t)) return tmp.second;
        for (int y : E[tmp.first])
        {
            --in[y];
            if (!in[y])
                q.push({y, tmp.second + 1});
        }
    }

    return -1;
}

inline void Zlin()
{
    cin >> h >> t >> k;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h_n[i] >> t_n[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> h_m[i] >> t_m[i];
    for (int i = 0; i <= k; i++)
        for (int j = 0; i + j <= k; j++)
        {
            for (int l = 1; l <= min(n, i); l++) G[get(i, j)].push_back(get(i - l + h_n[l], j + t_n[l]));
            for (int l = 1; l <= min(m, j); l++) G[get(i, j)].push_back(get(i + h_m[l], j - l + t_m[l]));
        }
    for (int i = 0; i <= k; i++)
        for (int j = 0; i + j <= k; j++)
            for (int l = 0; l < G[get(i, j)].size(); l++)
            {
                int x = G[get(i, j)][l];
                if (x / 400 + x % 400 > k) G[get(i, j)][l] = 100000;
            }
    dijkstra();
    if (dis[0] != INF)
    {
        cout << "Ivan\n" << dis[0];
        return;
    }
    int x = topo_sort();
    if (x == -1) cout << "Draw";
    else cout << "Zmey\n" << x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
