#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n, m;
int Q[100010]{}, f[100010][33]{};

void ST_prework()
{
    for (int i = 1; i <= n; i++)
        f[i][0] = Q[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int ST_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> Q[i];
    ST_prework();
    for (int i = m; i <= n; i++)
        cout << ST_query(i - m + 1, i) << '\n';
}