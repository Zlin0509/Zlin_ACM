#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n, m, a, b, c;
priority_queue<int> p;
priority_queue<int, vi, greater<int>> q;
int cal(int x) { return a * x * x + b * x + c; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        for (int j = 1; j <= m; j++)
            if (p.size() < m || cal(j) < p.top())
                p.push(cal(j));
        while (p.size() > m)
            p.pop();
    }
    while (!p.empty())
        q.push(p.top()), p.pop();
    while (!q.empty())
        cout << q.top() << " ", q.pop();
}