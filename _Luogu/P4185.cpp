#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, q, e = 0;
int f[100010]{}, num[100010]{};
int ans[100010]{};

struct xx
{
    int p, q, r;
    friend bool operator<(const xx &a, const xx &b) { return a.r > b.r; }
} t[100010]{};

struct ss
{
    int k, v, id;
    friend bool operator<(const ss &a, const ss &b) { return a.k > b.k; }
} T[100010]{};

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void add(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    f[fy] = fx;
    num[fx] += num[fy];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        f[i] = i, num[i] = 1;

    for (int i = 1, p, q, r; i < n; i++)
        cin >> t[i].p >> t[i].q >> t[i].r;
    sort(t + 1, t + n);

    for (int i = 1; i <= q; i++)
        cin >> T[i].k >> T[i].v, T[i].id = i;
    sort(T + 1, T + 1 + q);

    int cnt = 1;
    for (int i = 1; i <= q; i++)
    {
        while (cnt < n && t[cnt].r >= T[i].k)
        {
            add(t[cnt].p, t[cnt].q);
            ++cnt;
        }
        ans[T[i].id] = num[find(T[i].v)] - 1;
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}