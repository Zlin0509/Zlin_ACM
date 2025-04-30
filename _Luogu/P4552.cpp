#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[100010]{}, diff[100010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        diff[i] = a[i] - a[i - 1];
    diff[1] = 0;
    long long num = 0, ans = 0;
    long long l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if(diff[i] > 0)
        {
            r += diff[i];
        }
        else
            l -= diff[i];
    }
    num = max(l, r);
    ans = abs(r - l) + 1;
    cout << num << '\n'
            << ans << '\n';
}