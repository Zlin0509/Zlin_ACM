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

constexpr int N = 3e3 + 10;
vi a[N];
queue<pii> q;
int p[N][N];
int n, m, k;
map<pair<pii, int>, int> ch;

inline void Zlin()
{
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ch[{{a, b}, c}]++;
    }
    pii ans = {-1, -1};
    q.push({1, 1});
    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if (v == n)
        {
            ans = {u, v};
            break;
        }
        for (int i : a[v])
        {
            if (p[v][i] || ch[{{u, v}, i}])continue;
            p[v][i] = u;
            q.push({v, i});
        }
    }
    if (ans.first == -1)
    {
        cout << -1 << '\n';
        return;
    }
    vi path;
    while (ans.second != 1)
    {
        path.push_back(ans.second);
        ans = {p[ans.first][ans.second], ans.first};
    }
    cout << path.size() << '\n';
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (int it : path)
        cout << it << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
