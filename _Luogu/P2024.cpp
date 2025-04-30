#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, k, ans = 0;
int f[150010]{};
int a, x, y, fx, fy;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n * 3; i++)
        f[i] = i;
    while (k--)
    {
        cin >> a >> x >> y;
        if (x > n || y > n || (x == y && a == 2))
        {
            ++ans;
            continue;
        }
        if (a == 1)
        {
            if (find(x) == find(y + n) || find(x + n) == find(y))
                ++ans;
            else
            {
                f[find(x)] = find(y);
                f[find(x + n)] = find(y + n);
                f[find(x + n + n)] = find(y + n + n);
            }
        }
        else
        {
            if (find(x) == find(y) || find(y + n) == find(x))
                ++ans;
            else
            {
                f[find(x)] = find(y + n + n);
                f[find(x + n)] = find(y);
                f[find(x + n + n)] = find(y + n);
            }
        }
    }
    cout << ans;
}