#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int T[600010]{};
int n, m;

int ask(int l, int r)
{
    int ans = 0;
    for (; r; r -= lowbit(r))
        ans += T[r];
    --l;
    for (; l; l -= lowbit(l))
        ans -= T[l];
    return ans;
}

void change(int x, int k)
{
    for (; x <= n; x += lowbit(x))
        T[x] += k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        change(i, x);
    }
    int a, x, y;
    while (m--)
    {
        cin >> a >> x >> y;
        if (a == 1)
            change(x, y);
        else
            cout << ask(x, y) << '\n';
    }
}