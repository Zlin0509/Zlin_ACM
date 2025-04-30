#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll a, b, x, y, last = 0;
ll n, T, num, zz = 0;
ll f[1000010]{}, S[1000010]{};
ll A[1000010]{}, B[1000010]{}, D[1000010]{};
ll Mx[1000010]{}, v[1000010]{};
vll c[1000010]{};
pair<ll, ll> M[1000010]{};

inline int find(ll x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline bool check(ll x, ll y) { return v[x] * y >= v[y] * x ? 1 : 0; }
inline void merge(ll x, ll y, ll &tot, ll &cnt)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    tot -= (S[fy] * S[fy] + S[fx] * S[fx]), --cnt;
    S[fx] += S[fy];
    tot += S[fx] * S[fx];
    f[fy] = fx;
}

inline void prework()
{
    ll tot = 0, cnt = 0;
    for (int i = 1; i <= num; i++)
    {
        tot += c[i].size(), cnt += c[i].size();
        for (auto it : c[i])
        {
            if (it != 1 && A[it - 1] <= B[i])
                merge(it, it - 1, tot, cnt);
            if (it != n && A[it + 1] <= B[i])
                merge(it, it + 1, tot, cnt);
        }
        D[++zz] = cnt;
        v[i] = tot;
        if (check(i, Mx[cnt]))
            Mx[cnt] = i;
        M[i] = {cnt, tot};
    }
    sort(D + 1, D + 1 + zz);
    zz = unique(D + 1, D + 1 + zz) - D - 1;
}

inline void ST_prework()
{
    
}

inline int ST_query(int l,int r)
{
    int k = log(r - l + 1) / log(2);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> A[i], f[i] = i, S[i] = 1, B[i] = A[i];
    sort(B + 1, B + 1 + n);
    num = unique(B + 1, B + 1 + n) - B - 1;

    // for (int i = 1; i <= num; i++)
    //     cout << B[i] << ' ';
    // cout << '\n';

    for (int i = 1; i <= n; i++)
        c[lower_bound(B + 1, B + 1 + num, A[i]) - B].push_back(i);
    prework();
    ST_prework();

    // for (int i = 1; i <= zz; i++)
    //     cout << D[i] << ' ';
    // cout << '\n';

    ll l, r, ans;
    while (T--)
    {
        cin >> a >> b >> x >> y;
        l = (a * last + x - 1) % n + 1;
        r = (b * last + y - 1) % n + 1;
        if (l > r)
            swap(l, r);

        auto it = lower_bound(D + 1, D + 1 + zz, l) - D;
        // cout << D[it] << ' ' << it << '\n';
        if (it > zz || D[it] > r)
        {
            cout << "-1 -1" << '\n';
            cout << l << ' ' << r << ' ' << last % n << '\n';
            last = 1;
            continue;
        }
        ans = D[it++];
        while (it <= zz && D[it] <= r)
        {
            // cout << *it << '\n';
            if (Mx[D[it]] > Mx[ans] && check(Mx[D[it]], Mx[ans]))
                ans = D[it];
            ++it;
        }
        // cout << ans << '\n';
        cout << v[Mx[ans]] << ' ' << B[Mx[ans]] << '\n';
        cout << l << ' ' << r << ' ' << last % n << '\n';
        last = v[Mx[ans]] * B[Mx[ans]];
    }
}