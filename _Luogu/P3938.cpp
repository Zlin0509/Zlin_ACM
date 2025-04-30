#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 3e5 + 20;
int n;
ll sum[N];
inline ll lca(ll u, ll v)
{
    while (u != v)
    {
        if (u > v)
            swap(u, v);
        int pos = lower_bound(sum + 1, sum + 61, v) - sum;
        v -= sum[pos - 1];
    }
    return u;
}
inline void Zlin()
{
    cin >> n;
    sum[1] = 1;
    for (int i = 2; i <= 60; i++)
        sum[i] = sum[i - 1] + sum[i - 2];
    for (int i = 1; i <= n; i++)
    {
        ll u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}