#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n, q;
int a[50010]{}, f1[50010][33]{}, f2[50010][33]{};

void ST_prework_1()
{
    for (int i = 1; i <= n; i++)
        f1[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
}
void ST_prework_2()
{
    for (int i = 1; i <= n; i++)
        f2[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
}

int ST_query_1(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f1[l][k], f1[r - (1 << k) + 1][k]);
}
int ST_query_2(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ST_prework_1();
    ST_prework_2();
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << ST_query_1(l, r) - ST_query_2(l, r) << '\n';
    }
}