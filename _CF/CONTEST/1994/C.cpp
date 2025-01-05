#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll ans;
int n, x;
int a[200005];
ll sum[200005];
int Next[200005];
ll aa[200005];

void Zlin()
{
    memset(aa, 0, sizeof(aa));
    memset(Next, 0, sizeof(Next));
    ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1, pos; i <= n; i++)
    {
        pos = upper_bound(sum + 1, sum + n + 1, sum[i - 1] + x) - sum;
        // cout << pos << ' ';
        Next[i] = pos;
    }
    // cout << '\n';
    for (int i = n; i >= 1; i--)
    {
        aa[i] = Next[i] - i + aa[Next[i] + 1];
        // cout << aa[i] << ' ';
        ans += aa[i];
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