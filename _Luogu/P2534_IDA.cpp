#include <bits/stdc++.h>
using namespace std;

int n, k = 0, cc = 0;
int a[20]{}, b[20]{};

bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != i)
            return false;
    return true;
}

bool sum(int step)
{
    int cnt = step;
    for (int i = 1; i <= n; i++)
    {
        if (abs(a[i] - a[i + 1]) != 1)
        {
            ++cnt;
            if (cnt > k)
                return false;
        }
    }
    return true;
}

void IDA(int step, int pre)
{
    if (check() || cc)
    {
        cc = 1;
        return;
    }
    if (step >= k)
        return;

    for (int i = 2; i <= n; i++)
    {
        if (pre == i || abs(a[i] - a[i + 1]) == 1)
            continue;
        reverse(a + 1, a + 1 + i);
        if (sum(step))
            IDA(step + 1, i);
        reverse(a + 1, a + 1 + i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];

    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    a[n + 1] = n + 1;

    if (check())
    {
        cout << 0 << '\n';
        return 0;
    }

    while (++k)
    {
        IDA(0, 0);
        if (cc)
        {
            cout << k << '\n';
            return 0;
        }
    }
}