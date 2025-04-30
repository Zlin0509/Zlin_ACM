#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

long long n, ans;
long long a[50010]{}, b[50010]{};

int qGCD(int a,int b)
{
    int az = __builtin_ctz(a), bz= __builtin_ctz(b);
    int z = min(az, bz), dif;
    b >>= bz;
    while(a)
    {
        a >>= az;
        dif = abs(b - a);
        az = __builtin_ctz(dif);
        if (a < b)
            b = a;
        a = dif;
    }
    return b << z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];

    for (long long i = 1,y; i <= n;i++)
    {
        ans = 0;
        y = 1;
        for (long long j = 1,x; j <= n;j++)
        {
            y = y * i % mod;
            x = y * qGCD(a[i], b[j]) % mod;
            ans = (ans + x) % mod;
        }
        cout << ans << '\n';
    }

}