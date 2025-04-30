#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 5;

int n, m;
int tag[N], a[N], b[N], sum[N], belong[N], l[N], r[N], len, tot;

inline void change(int lc, int rc)
{
    int p = belong[lc], q = belong[rc];
    if (p == q)
    {
        for (int i = lc; i <= rc; i++)
        {
            a[i] ? --sum[p] : ++sum[p];
            a[i] ^= 1;
        }
        return;
    }
    for (int i = p + 1; i <= q - 1; i++)
        tag[i] ^= 1;
    for (int i = lc; i <= r[p]; i++)
    {
        a[i] ? --sum[p] : ++sum[p];
        a[i] ^= 1;
    }
    for (int i = l[q]; i <= rc; i++)
    {
        a[i] ? --sum[q] : ++sum[q];
        a[i] ^= 1;
    }
}

inline int query(int lc, int rc)
{
    int p = belong[lc], q = belong[rc];
    int ans = 0;
    if (p == q)
    {
        for (int i = lc; i <= rc; i++)
            if (tag[p] ^ a[i])
                ++ans;
        return ans;
    }
    for (int i = p + 1, x; i <= q - 1; i++)
    {
        if (tag[i])
            ans += r[i] - l[i] + 1 - sum[i];
        else
            ans += sum[i];
    }
    for (int i = lc; i <= r[p]; i++)
        if (tag[p] ^ a[i])
            ++ans;
    for (int i = l[q]; i <= rc; i++)
        if (tag[q] ^ a[i])
            ++ans;
    return ans;
}

void Zlin()
{
    cin >> n >> m;
    init();
    int x, y, z;
    while (m--)
    {
        cin >> x >> y >> z;

        if (y > z)
            swap(y, z);

        if (x == 0)
            change(y, z);
        else
            cout << query(y, z) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}