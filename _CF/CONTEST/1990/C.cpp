#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int n, Max, l, Max2;
ll ans;
int a[200010]{}, cnt[200010]{};
void Zlin()
{
    Max = 0, ans = 0, Max2 = 0;
    memset(cnt, 0, sizeof cnt);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ++cnt[a[i]];
        if (cnt[a[i]] == 2 && a[i] > Max)
        {
            if (i - l >= 2)
                ans += 1ll * (i - l) * Max * (n - i + 1);
            else
                ans += 1ll * Max2 * (n - i + 1);
            if (i - l >= 2)
                Max2 = Max;
            l = i, Max = a[i];
        }
        ans += a[i];
        ans += 1ll * Max * (i - l + 1);
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