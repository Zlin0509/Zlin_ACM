//
// Created by 27682 on 2025/3/11.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Ftree
{
private:
    vi t;

public:
    void init(int n)
    {
        t.assign(n + 1, 0);
    }

    void upd(int i, int v)
    {
        while (i < t.size())
        {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r)
    {
        if (l <= 1) return qry1(r);
        return qry1(r) - qry1(l - 1);
    }
} t;

inline void Zlin()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vi a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + (s[i] == '1' ? 1 : -1);
    t.init(n * 2 + 5);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            ++cnt;
        a[i] += n + 1;
        t.upd(a[i], 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!cnt)
            continue;
        ans += t.qry2(a[i - 1], n * 2 + 5);
        t.upd(a[i], -1);
        if (s[i] == '1')
            --cnt;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
