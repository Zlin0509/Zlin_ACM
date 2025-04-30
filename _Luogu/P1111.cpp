#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m;
int H[200010]{};
struct ss
{
    int v, u;
    int w;
    friend bool operator<(const ss &a, const ss &b) { return a.w < b.w; }
} h[200010]{};

int find(int u)
{
    return H[u] == u ? u : H[u] = find(H[u]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> h[i].u >> h[i].v >> h[i].w;
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    sort(h + 1, h + 1 + m);
    for (int i = 1; i <= n; i++)
        H[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int fx = find(h[i].u), fy = find(h[i].v);
        if (fx != fy)
        {
            H[fx] = fy;
            --n;
        }
        if (n == 1)
        {
            cout << h[i].w;
            return 0;
        }
    }
    cout << "-1";
}