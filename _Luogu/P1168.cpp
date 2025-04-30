#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, x1, x2;
priority_queue<int, vector<int>, greater<int>> p; // 小
priority_queue<int> q;                            // 大

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> x1;
    cout << x1 << '\n';
    if (n == 1)
        return 0;

    cin >> x2;
    if (x1 <= x2)
    {
        q.push(x1);
        p.push(x2);
    }
    else
    {
        q.push(x2);
        p.push(x1);
    }

    for (int i = 3, x; i <= n; i++)
    {
        cin >> x;
        if (x <= q.top())
            q.push(x);
        else
            p.push(x);
        if (q.size() > p.size() && q.size() - p.size() > 1)
        {
            p.push(q.top());
            q.pop();
        }
        if (p.size() > q.size() && p.size() - q.size() > 1)
        {
            q.push(p.top());
            p.pop();
        }
        if (i & 1)
        {
            if (p.size() > q.size())
            {
                cout << p.top() << '\n';
            }
            else
            {
                cout << q.top() << '\n';
            }
        }
    }
}