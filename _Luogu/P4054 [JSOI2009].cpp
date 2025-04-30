#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
int n, m, q, ans;
int a[310][310]{};
int t[101][310][310]{};

void add(int color, int i, int j, int k)
{
    for (; j <= m; j += lowbit(j))
        t[color][i][j] += k;
}

int ask(int color, int i, int l, int r)
{
    int sum = 0;
    for (; r; r -= lowbit(r))
        sum += t[color][i][r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= t[color][i][l];
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], add(a[i][j], i, j, 1);
    cin >> q;
    int zz, xa, ya, xb, yb, c;
    while (q--)
    {
        cin >> zz;
        if (zz == 1)
        {
            cin >> xa >> ya >> c;
            add(a[xa][ya], xa, ya, -1);
            a[xa][ya] = c;
            add(a[xa][ya], xa, ya, 1);
        }
        else
        {
            ans = 0;
            cin >> xa >> xb >> ya >> yb >> c;
            for (int i = xa; i <= xb; i++)
                ans += ask(c, i, ya, yb);
            cout << ans << '\n';
        }
    }
    return 0;
}