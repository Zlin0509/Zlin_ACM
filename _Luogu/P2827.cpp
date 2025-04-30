#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = -0x3f3f3f3f;

queue<int> a, b, c;
int n, m, q, t, x1, x2, x3, z, d;
long double u, v;
int dd[700010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> dd[i];
    }
    sort(dd + 1, dd + 1 + n);
    for (int i = n; i >= 1; i--)
        a.push(dd[i]);

    for (int i = 1; i <= m; i++)
    {
        if (!a.empty())
            x1 = a.front() + q * (i - 1);
        else
            x1 = INF;
        if (!b.empty())
            x2 = b.front() + q * (i - 1);
        else
            x2 = INF;
        if (!c.empty())
            x3 = c.front() + q * (i - 1);
        else
            x3 = INF;
        if (x1 >= x2 && x1 >= x3)
            z = x1, a.pop();
        else if (x2 >= x1 && x2 >= x3)
            z = x2, b.pop();
        else
            z = x3, c.pop();
        if (i % t == 0)
            cout << z << ' ';
        d = u * z / v;
        b.push(d - q * i);
        c.push(z - d - q * i);
    }
    cout << '\n';
    int cnt = 0;
    while (!a.empty() || !b.empty() || !c.empty())
    {
        ++cnt;
        if (!a.empty())
            x1 = a.front() + q * m;
        else
            x1 = INF;
        if (!b.empty())
            x2 = b.front() + q * m;
        else
            x2 = INF;
        if (!c.empty())
            x3 = c.front() + q * m;
        else
            x3 = INF;
        if (x1 >= x2 && x1 >= x3)
            z = x1, a.pop();
        else if (x2 >= x1 && x2 >= x3)
            z = x2, b.pop();
        else
            z = x3, c.pop();
        if (cnt % t == 0)
            cout << z << ' ';
    }
}