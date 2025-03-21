//
// Created by 27682 on 2025/3/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e6 + 10;


inline void Zlin()
{
    int n, q;
    cin >> n >> q;
    vi idx(n + 1), f(n + 1);
    vector<vi> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        idx[i] = f[i] = i;
        a[i].push_back(i);
    }
    while (q--)
    {
        int op, a, b;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            idx[b] = a;
        }
        if (op == 2)
        {
            cin >> a >> b;
        }
        if (op == 3)
        {
            cin >> a >> b;
            swap(idx[a], idx[b]);
        }
        if (op == 4)
        {
            cin >> a;
            cout << idx[f[a]] << endl;
        }
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
