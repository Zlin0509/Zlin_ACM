#include<bits/stdc++.h>
using namespace std;

long long n, m, s;
long long ans = 0x3f3f3f3f3f3f3f3f;
long long w[200010]{}, v[200010]{};
long long l[200010]{}, r[200010]{};
long long prei[200010]{}, pren[200010]{};

bool check(long long W)
{
    for (int i = 1; i <= n; i++)
    {
        if(w[i]>=W)
        {
            prei[i] = prei[i - 1] + v[i];
            pren[i] = pren[i - 1] + 1;
        }
        else
        {
            prei[i] = prei[i - 1];
            pren[i] = pren[i - 1];
        }
    }
    long long x = 0;
    for (int i = 1; i <= m; i++)
    {
        x += (pren[r[i]] - pren[l[i] - 1]) * (prei[r[i]] - prei[l[i] - 1]);
    }
    long long Y = llabs(s - x);
    ans = min(ans, Y);
    if(x>s)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    long long l1 = 1e9, r1 = 0, mid;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        l1 = min(l1, w[i]);
        r1 = max(r1, w[i]);
    }
        
    for (int i = 1; i <= m;i++)
        cin >> l[i] >> r[i];

    r1 += 2;
    l1 -= 1;

    while(l1<r1)
    {
        mid = l1 + r1 >> 1;
        if(check(mid))
            l1 = mid + 1;
        else
            r1 = mid;
    }
    cout << ans << '\n';
}