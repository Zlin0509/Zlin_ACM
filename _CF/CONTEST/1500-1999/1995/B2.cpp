#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll n, m;
struct ss
{
    ll a, c;
    friend bool operator<(const ss &a, const ss &b)
    {
        return a.a < b.a;
    }
} e[N];

inline void
Zlin()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> e[i].a;
    for (int i = 1; i <= n; i++)
        cin >> e[i].c;
    sort(e + 1, e + 1 + n);
    ll x, y, z, sum, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        x = m / e[i].a;
        x = min(x, e[i].c);
        sum = x * e[i].a;
        if (i != n && e[i + 1].a == e[i].a + 1)
        {
            z = m - sum;
            y = z / e[i + 1].a;
            y = min(y, e[i + 1].c);
            sum += y * e[i + 1].a;
            z -= y * e[i + 1].a;
            z = min(z, x);
            z = min(z, e[i + 1].c - y);
            sum += z;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}