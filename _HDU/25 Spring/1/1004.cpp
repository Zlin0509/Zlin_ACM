//
// Created by 27682 on 2025/3/7.
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

constexpr int N = 1e5 + 10;

int n, q;
int st[N][22];
int a[N];
int l[N], r[N];
int c[N];

inline void ST_prework()
{
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

inline int ST_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int op[N];

inline void Zlin()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int lx = 0, rx = 0, top = 1;
    multiset<int> sr;
    multiset<int, greater<int>> sl;
    if (c[1] > c[2])
        sr.insert(c[1]);
    else
        sl.insert(c[1]);
    l[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (c[i] > c[i - 1])
            sr.insert(c[i]);
        else
            sl.insert(c[i]);
        if (i > 2 && c[i] > c[i - 1] == c[i - 1] > c[i - 2])
        {
            while (top < i - 1)
            {
                r[top] = i - 1;
                if (c[top] > c[top - 1])
                    sr.erase(sr.find(c[top]));
                else
                    sl.erase(sl.find(c[top]));
                ++top;
            }
        }
        while (!sl.empty() && !sr.empty() && *sl.begin() >= *sr.begin())
        {
            r[top] = i - 1;
            if (c[top] > c[top - 1])
                sr.erase(sr.find(c[top]));
            else
                sl.erase(sl.find(c[top]));
            ++top;
        }

        l[i] = top;
    }
    for (int i = top; i <= n; i++)
        r[i] = n;
    for (int i = 1; i <= n; i++)
        cout << l[i] << " " << r[i] << endl;
    while (q--)
    {
    }
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
