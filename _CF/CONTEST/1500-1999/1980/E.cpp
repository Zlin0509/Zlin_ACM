#include <bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n"
#define fi first
#define se second
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const double eps = 1e-6;
const ll b1 = 131, b2 = 151;
const ll mod1 = 1145141, mod2 = 20080103;
struct Hash
{
    ll h1, h2;
    friend Hash operator+(const Hash &a, const Hash &b)
    {
        return {(a.h1 + b.h1) % mod1, (a.h2 + b.h2) % mod2};
    }
    friend Hash operator*(const Hash &a, const ll &b)
    {
        return {(a.h1 * b) % mod1, (a.h2 * b) % mod2};
    }
    friend bool operator==(const Hash &a, const Hash &b)
    {
        return (a.h1 == b.h1) && (a.h2 == b.h2);
    }
    friend bool operator<(const Hash &a, const Hash &b)
    {
        if (a.h1 == b.h1)
            return a.h2 < b.h2;
        return (a.h1 < b.h1);
    }
} h[N];
ll n, m;
vector<vector<ll>> a, b;
vector<Hash> c1, c2;
void sol()
{
    cin >> n >> m;
    a.clear(), b.clear();
    c1.clear(), c2.clear();
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++)
    {
        Hash hsh = {0, 0};
        vector<ll> p;
        p.resize(m);
        for (int j = 0; j < m; j++)
            cin >> p[j];
        a[i] = p;
        sort(p.begin(), p.end());
        for (int j = 0; j < m; j++)
            hsh = hsh + (h[j] * p[j]);
        c1.push_back(hsh);
    }
    for (int i = 0; i < n; i++)
    {
        Hash hsh = {0, 0};
        vector<ll> p;
        p.resize(m);
        for (int j = 0; j < m; j++)
            cin >> p[j];
        b[i] = p;
        sort(p.begin(), p.end());
        for (int j = 0; j < m; j++)
            hsh = hsh + (h[j] * p[j]);
        c2.push_back(hsh);
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    for (int i = 0; i < n; i++)
    {
        if (c1[i] == c2[i])
            continue;
        cout << "NO\n";
        return;
    }
    c1.clear(), c2.clear();
    for (int j = 0; j < m; j++)
    {
        Hash hsh = {0, 0};
        vector<ll> p;
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = a[i][j];
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++)
            hsh = hsh + (h[i] * p[i]);
        c1.push_back(hsh);
    }
    for (int j = 0; j < m; j++)
    {
        Hash hsh = {0, 0};
        vector<ll> p;
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = b[i][j];
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++)
            hsh = (hsh + (h[i] * p[i]));
        c2.push_back(hsh);
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    for (int i = 0; i < m; i++)
    {
        if (c1[i] == c2[i])
            continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main()
{
    h[0] = {1, 1};
    for (int i = 1; i <= N - 5; i++)
    {
        h[i].h1 = h[i - 1].h1 * b1 % mod1;
        h[i].h2 = h[i - 1].h2 * b2 % mod2;
    }
    ll ttt;
    cin >> ttt;
    while (ttt--)
        sol();
    return 0;
}