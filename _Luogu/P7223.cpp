#include <bits/stdc++.h>
#define Mod 998244353

using namespace std;

long long binpow(long long b, long long p, long long k)
{
    b %= k;
    long long res = 1;
    while (p > 0)
    {
        if (p & 1)
            res = res * b % k;
        b = b * b % k;
        p >>= 1;
    }
    return res;
}

long long a[1000086];

int main()
{
    long long n, p;
    long long ans = 1;
    scanf("%lld%lld", &n, &p);
    for (long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (long long i = 1; i <= n; i++)
    {
        ans *= (binpow(p, a[i], Mod) % Mod + 1);
        ans %= Mod;
    }
    printf("%lld", ans % Mod);
    return 0;
}