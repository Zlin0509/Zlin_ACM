//
// Created by Zlin on 2025/2/8.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n, x, y;
string a, b, c;
ll ans = 0;
ll l[2], r[2];


inline void Zlin()
{
    cin >> n >> x >> y;
    cin >> a >> b >> c;
    for (int i = 0; i < n; i++)
    {
        int aa = a[i] - '0';
        int bb = b[i] - '0';
        int cc = c[i] - '0';
        if (cc && aa == bb)
            l[aa]++;
        if (!cc && aa != bb)
            r[aa]++;
    }

    if (2ll * x <= y)
    {
        ans = l[0] + l[1] + r[0] + r[1];
        ans *= x;
    }
    else
    {
        ll sl = l[0] + l[1], sr = r[0] + r[1];
        ans = min(sl, sr) * y;
        if (sl >= sr)
        {
            ll cnt = abs(l[0] - l[1]);
            sl -= sr;
            cnt = max(0ll, cnt - sr);
            sl -= cnt;
            ans += sl / 2 * y + x * (sl & 1) + cnt * x;
        }
        else
        {
            ll cnt = abs(r[0] - r[1]);
            sr -= sl;
            cnt = max(0ll, cnt - sl);
            sr -= cnt;
            ans += sr / 2 * y + x * (sr & 1) + cnt * x;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
