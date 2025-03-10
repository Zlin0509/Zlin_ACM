//
// Created by Zlin on 2025/1/25.
//

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;

int n, q, p, x;
vi a;

struct Node
{
    int Min1, Min2, Max1, Max2, ans1, ans2;
} t[N << 2];

inline void pushup(int i)
{
    t[i].Min1 = min(t[i << 1].Min1, t[i << 1 | 1].Min1);
    t[i].Min2 = min(t[i << 1].Min2, t[i << 1 | 1].Min2);
    t[i].Max1 = max(t[i << 1].Max1, t[i << 1 | 1].Max1);
    t[i].Max2 = max(t[i << 1].Max2, t[i << 1 | 1].Max2);

    t[i].ans1 = max(t[i << 1].ans1, t[i << 1 | 1].ans1);
    t[i].ans1 = max(t[i].ans1, t[i << 1].Max1 - t[i << 1 | 1].Min1);
    t[i].ans2 = max(t[i << 1].ans2, t[i << 1 | 1].ans2);
    t[i].ans2 = max(t[i].ans2, t[i << 1 | 1].Max2 - t[i << 1].Min2);
}

inline void build(int i, int l, int r)
{
    if (l == r)
    {
        t[i].Min1 = t[i].Max1 = a[l] + l;
        t[i].Min2 = t[i].Max2 = a[l] - l;
        t[i].ans1 = t[i].ans2 = 0;
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    pushup(i);
}


inline void update(int i, int l, int r, int x, int val)
{
    if (l > x || r < x)
        return;
    if (l == r)
    {
        t[i].Min1 = t[i].Max1 = val + x;
        t[i].Min2 = t[i].Max2 = val - x;
        t[i].ans1 = t[i].ans2 = 0;
        return;
    }
    int mid = l + r >> 1;
    update(i << 1, l, mid, x, val);
    update(i << 1 | 1, mid + 1, r, x, val);
    pushup(i);
}

inline void Zlin()
{
    cin >> n >> q;

    a.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    cout << max(t[1].ans1, t[1].ans2) << endl;
    while (q--)
    {
        cin >> p >> x;
        update(1, 1, n, p, x);
        cout << max(t[1].ans1, t[1].ans2) << endl;
    }
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
