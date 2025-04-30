#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

struct ss
{
    int a, b, c;
    friend bool operator<(const ss &a, const ss &b) { return a.c > b.c; }
} z[100010]{};
int n, m;
int f[20010]{}, d[20010]{};

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
        cin >> z[i].a >> z[i].b >> z[i].c;
    sort(z + 1, z + 1 + m);

    for (int i = 1, fx, fy; i <= m; i++)
    {
        fx = find(z[i].a);
        fy = find(z[i].b);
        if (fx == fy)
        {
            cout << z[i].c;
            return 0;
        }
        if (!d[fx])
            d[fx] = fy;
        else
            f[fy] = find(d[fx]);
        if (!d[fy])
            d[fy] = fx;
        else
            f[fx] = find(d[fy]);
    }
    cout << '0';
}