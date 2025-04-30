#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll n, h, r;
struct ss
{
    ll x, y, z;
    friend bool operator<(const ss &a, const ss &b) { return a.z < b.z; }
} T[1010]{};
int u[1010]{};
vi a, b;

ll cal(ss a, ss b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

int find(int x)
{
    return u[x] == x ? x : u[x] = find(u[x]);
}

void solve()
{
    a.clear();
    b.clear();
    cin >> n >> h >> r;
    for (int i = 1; i <= n; i++)
        cin >> T[i].x >> T[i].y >> T[i].z;
    for (int i = 1; i <= n; i++)
    {
        u[i] = i;
        if (T[i].z - r <= 0)
            a.push_back(i);
        if (T[i].z + r >= h)
            b.push_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            // cout << cal(T[i], T[j]) << '\n';
            if (cal(T[i], T[j]) > 4 * r * r)
                continue;
            if (cal(T[i], T[j]) <= 4 * r * r)
            {
                // cout << i << ' ' << j << '\n';
                int fx = find(i), fy = find(j);
                if (fx != fy)
                    u[fy] = fx;
            }
        }
    }

    for (auto ia : a)
    {
        for (auto ib : b)
        {
            // cout << find(ia) << ' ' << find(ib) << '\n';
            if (find(ib) == find(ia))
            {
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    cout << "No" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TTT;
    cin >> TTT;
    while (TTT--)
        solve();
}