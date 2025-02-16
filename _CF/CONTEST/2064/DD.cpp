//
// Created by Zlin on 2025/2/16.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll DOM = 1LL << 30;
const int N = 30;

struct Interval
{
    ll L, R;
};

vector<Interval> solve_bad(int pos, ll a, bool tight, ll b, ll c)
{
    vector<Interval> res;
    if (pos < 0)
    {
        if (tight) return res;
        return {{a, a + 1}};
    }
    if (!tight)
    {
        ll L = a << (pos + 1);
        ll R = L + (1LL << (pos + 1));
        return {{L, R}};
    }
    int b_bit = (b >> pos) & 1;
    int c_bit = (c >> pos) & 1;
    for (int a_bit = 0; a_bit < 2; a_bit++)
    {
        int x = a_bit ^ b_bit;
        if (x > c_bit) continue;
        ll new_val = (a << 1) | a_bit;
        if (x < c_bit)
        {
            ll L = new_val << pos;
            ll R = L + (1LL << pos);
            res.push_back({L, R});
        }
        else
        {
            vector<Interval> sub = solve_bad(pos - 1, new_val, true, b, c);
            for (auto& it : sub)
                res.push_back(it);
        }
    }
    sort(res.begin(), res.end(), [](const Interval& A, const Interval& B)
    {
        return A.L < B.L;
    });
    return res;
}

vector<Interval> complementIntervals(const vector<Interval>& bad)
{
    vector<Interval> good;
    ll cur = 0;
    for (auto& it : bad)
    {
        if (cur < it.L)
            good.push_back({cur, it.L});
        cur = max(cur, it.R);
    }
    if (cur < DOM)
        good.push_back({cur, DOM});
    return good;
}

vector<Interval> getGood(ll b, ll c)
{
    vector<Interval> bad = solve_bad(N - 1, 0, true, b, c);
    vector<Interval> good = complementIntervals(bad);
    return good;
}

vector<Interval> intersectUnion(const vector<Interval>& A, const vector<Interval>& B)
{
    vector<Interval> C;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size())
    {
        ll L = max(A[i].L, B[j].L);
        ll R = min(A[i].R, B[j].R);
        if (L < R)
            C.push_back({L, R});
        if (A[i].R < B[j].R)
            i++;
        else
            j++;
    }
    return C;
}

bool inUnion(const vector<Interval>& U, ll x)
{
    int lo = 0, hi = U.size() - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (U[mid].L <= x && x < U[mid].R)
            return true;
        else if (x < U[mid].L)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

inline void Zlin()
{
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[n - i + 1];

    vi Q(n + 1, 0);
    for (int i = 1; i <= n; i++)
        Q[i] = Q[i - 1] ^ a[i];

    vector<vector<Interval>> Iset;
    Iset.push_back({{0, DOM}});
    for (int i = 1; i <= n; i++)
    {
        vector<Interval> S = getGood(Q[i - 1], a[i]);
        vector<Interval> newI = intersectUnion(Iset.back(), S);
        Iset.push_back(newI);
        if (newI.empty())
        {
            for (int j = i + 1; j <= n; j++)
                Iset.push_back({});
            break;
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) >> 1;
            if (inUnion(Iset[mid], x))
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << lo << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
