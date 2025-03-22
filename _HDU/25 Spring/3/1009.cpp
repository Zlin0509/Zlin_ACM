//
// Created by 27682 on 2025/3/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e6 + 10;


inline int find(vi& f, int u)
{
    return f[u] == u ? u : f[u] = find(f, f[u]);
}

void merge(vi& f, int x, int y)
{
    int fx = find(f, x), fy = find(f, y);
    if (fx == fy)
        return;
    f[fy] = fx;
}

inline void Zlin()
{
    int n, q;
    cin >> n >> q;
    vi f(n + 1), down(n + 1), up(n + 1), be(n + 1);
    for (int i = 1; i <= n; i++)
        f[i] = down[i] = up[i] = be[i] = i;
    while (q--)
    {
        int op, a, b;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            merge(f, down[a], down[b]);
        }
        if (op == 2)
        {
            cin >> a >> b;
            be[a] = down[b];
        }
        if (op == 3)
        {
            cin >> a >> b;
            swap(up[down[a]], up[down[b]]);
            swap(down[a], down[b]);
        }
        if (op == 4)
        {
            cin >> a;
            cout << up[find(f, be[a])] << endl;
        }
    }
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
