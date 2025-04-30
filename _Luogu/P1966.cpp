#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const ll Mod = 1e8 - 3;
ll ans = 0;
int n;
int t[100010]{};
struct ss
{
    int a, id, c;
} a[100010]{}, b[100010]{};

bool cmp1(const ss &a, const ss &b) { return a.a < b.a; }
bool cmp2(const ss &a, const ss &b) { return a.id < b.id; }

void add(int i, int k)
{
    for (; i <= n; i += lowbit(i))
        t[i] += k;
}

int ask(int l, int r)
{
    int sum = 0;
    for (; r; r -= lowbit(r))
        sum += t[r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= t[l];
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].a;
        b[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + n, cmp1);
    for (int i = 1; i <= n; i++)
        a[i].c = b[i].id;
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = n; i >= 1; i--)
    {
        ans = (ans + ask(1, a[i].c)) % Mod;
        add(a[i].c, 1);
    }
    cout << ans;
}