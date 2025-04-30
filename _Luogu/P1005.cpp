#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 5, numl, numr; i >= 0; i--)
    {
        numl = 0, numr = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= (1 << (i + 1)))
                numl += (a[j] / (1 << i)) - 1;
            if (a[j] < (1 << i))
                ++numr;
        }
        // cout << numl << " " << numr << '\n';
        // for (int i = 0; i < n; i++)
        //     cout << a[i] << ' ';
        // cout << '\n';
        if (numl > numr)
            ans += (1 << (i + 1));
        numl = min(numl, numr);
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= (1 << (i + 1)))
                a[j] -= (1 << (i + 1));
            if (a[j] < (1 << i) && numl)
                --numl, a[j] += (1 << i);
        }
    }

    for (int i = 0; i < n; i++)
        if (a[i] & 1)
        {
            ++ans;
            break;
        }

    cout << ans << '\n';
}