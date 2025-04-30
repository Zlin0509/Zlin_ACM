//
// Created by 27682 on 2025/3/14.
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

constexpr int N = 1e6;

struct node
{
    int x, y, c;
};

int vis[N];
vi e[N];

inline void Zlin()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n * 3; i++)
    {
        vis[i] = 0;
        e[i].clear();
    }

    vector<node> a(m);
    set<int> need;
    for (auto& [x,y,c] : a)
    {
        cin >> x >> y >> c;
        need.insert(x);
    }
    vi in(n * 3 + 1);
    for (auto [x,y,c] : a)
    {
        int l1, l2, l3;
        l1 = (y + 1) / 2;
        l2 = 2 * n - x + 1;
        l3 = 2 * n + (x * 2 - 1 - y + 2) / 2;
        if (l1 != c && l2 != c && l3 != c)
        {
            cout << "No" << endl;
            return;
        }
        if (l1 != c)
            e[l1].push_back(c), ++in[c];
        if (l2 != c)
            e[l2].push_back(c), ++in[c];
        if (l3 != c)
            e[l3].push_back(c), ++in[c];
        need.insert(l1);
        need.insert(l2);
        need.insert(l3);
    }
    queue<int> have;
    for (int it : need)
        if (!in[it])
            have.push(it);
    while (!have.empty())
    {
        int u = have.front();
        have.pop();
        vis[u] = 1;
        for (int v : e[u])
        {
            --in[v];
            if (!in[v])
                have.push(v);
        }
    }
    for (int it : need)
        if (!vis[it])
        {
            cout << "No" << endl;
            return;
        }
    cout << "Yes" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
