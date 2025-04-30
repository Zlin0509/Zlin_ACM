#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 5;
ll ans[N], val[N];
int n, q;

struct node
{
    int i, pos, val;
};
vector<node> Do[N];

ll tag[N];
int size, tot, belong[N], L[N], R[N];
struct A
{
    int pos, val;
    friend bool cmp(const A &a, const A &b)
    {
        return a.val == b.val ? a.pos < b.pos : a.val < b.val;
    }
} a[N];
inline void prework()
{
    size = sqrt(q), tot = (q - 1) / size + 1;
    for (int i = 1; i <= tot; i++)
        L[i] = R[i - 1] + 1, R[i] = i * size;
    R[tot] = q;
    for (int i = 1; i <= tot; i++)
        for (int j = L[i]; j <= R[i]; j++)
            belong[j] = i;
}

inline void change(int l, int v)
{
}

inline int query(int pos, int v)
{
    int ans = 0;

    return ans;
}

void Zlin()
{
    memset(ans, -1, sizeof ans);
    cin >> n >> q;
    prework();
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1, l, r, x, op; i <= q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> x;
            Do[l].push_back(1, i, x);
            Do[r + 1].push_back(1, i, -x);
        }
        else
        {
            cin >> l >> x;
            Do[l].push_back(2, i, x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (node it : Do[i])
        {
            if (it.i == 1)
                change(1, it.pos, it.val);
            else
                ans[it.pos] = query(it.pos - 1, it.val - val[it.pos]);
        }
    }
    for (int i = 1; i <= q; i++)
        if (~ans[i])
            cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}