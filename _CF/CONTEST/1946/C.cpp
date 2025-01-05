#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int n, k;
vector<vi> t(100010);
int tot, mid, sum;
int used[100010]{};

void dfs(int fa, int x)
{
    used[x] = 1;
    for (int i : t[x])
        if (i != fa)
        {
            dfs(x, i);
            if (used[i] >= mid && sum - used[i] >= mid)
                ++tot, sum -= used[i];
            else
                used[x] += used[i];
        }
}

bool check()
{
    tot = 1;
    sum = n;
    memset(used, 0, sizeof(used));
    dfs(0, 1);
    return tot > k;
}

void solve()
{
    for (int i = 0; i < 100010; i++)
        t[i].clear();
    cin >> n >> k;
    for (int i = 1, l, r; i < n; i++)
    {
        cin >> l >> r;
        t[l].push_back(r);
        t[r].push_back(l);
    }
    int l = 1, r = n;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check())
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}