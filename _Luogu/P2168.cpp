#include <bits/stdc++.h>
using namespace std;

long long n, k, ans = 0, h = 0;

struct node
{
    long long h, w;
    bool operator<(const node &x) const
    {
        return x.w == w ? x.h < h : x.w < w;
    }
};

priority_queue<node> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        q.push({1, x});
    }
    while ((q.size() - 1) % (k - 1) != 0)
        q.push({1, 0});
    while (q.size() >= k)
    {
        long long sum = 0;
        for (int i = 1; i <= k; i++)
        {
            node z = q.top();
            q.pop();
            h = max(h, z.h);
            sum += z.w;
        }
        ans += sum;
        q.push({h + 1, sum});
    }
    cout << ans << '\n';
    cout << q.top().h - 1;
}