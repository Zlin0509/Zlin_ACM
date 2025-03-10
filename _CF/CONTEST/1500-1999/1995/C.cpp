#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll n, a[N], ans;
double cnt[N], c, eps = 1e-9;
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[i] = 0;
    ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1 && a[i] < a[i - 1])
        {
            cout << "-1\n";
            return;
        }
        cnt[i] = max(0.0, ceil(log2(log2(a[i - 1]) / log2(a[i])) - eps + cnt[i - 1]));
        ans += cnt[i];
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}