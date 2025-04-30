#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int k, n, cnt = 0, x1, x2;
int used[50010]{};
ll m, sum = 0;
struct ss
{
    int p, c, id;
} aa[50010]{};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p, q;
priority_queue<int, vector<int>, greater<int>> z;
bool cmp(const ss &a, const ss &b) { return a.c < b.c; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> aa[i].p >> aa[i].c;
        aa[i].id = i;
    }

    sort(aa + 1, aa + 1 + n, cmp);
    for (int i = 1; i <= k; i++)
    {
        sum += aa[i].c;
        ++used[i];
        if (sum > m)
        {
            cout << cnt;
            return 0;
        }
        ++cnt;
        z.push(aa[i].p - aa[i].c);
    }
    if (k == n)
    {
        cout << k;
        return 0;
    }

    for (int i = k + 1; i <= n; i++)
    {
        p.push({aa[i].p, i});
        q.push({aa[i].c, i});
    }

    for (int i = k + 1; i <= n; i++)
    {
        while (used[p.top().second])
            p.pop();
        while (used[q.top().second])
            q.pop();
        x1 = p.top().first;
        x2 = q.top().first + z.top();
        if (x1 <= x2)
        {
            ++used[p.top().second];
            p.pop();
            sum += x1;
        }
        else
        {
            ++used[q.top().second];
            z.pop();
            z.push(aa[q.top().second].p - aa[q.top().second].c);
            q.pop();
            sum += x2;
        }
        if (sum > m)
        {
            cout << cnt;
            return 0;
        }
        ++cnt;
    }
    cout << cnt;
}