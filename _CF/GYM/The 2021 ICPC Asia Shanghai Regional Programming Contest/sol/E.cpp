#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    int cnt = 1;
    int p = a[1];
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] - p >= k)
        {
            cnt++;
            p = a[i];
        }
    }

    cout << cnt << '\n';

    return 0;
}