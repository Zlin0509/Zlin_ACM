//
// Created by Zlin on 2025/2/11.
//

#include "bits/stdc++.h"
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

inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vector<pii> q(m);
    for (int i = 0, c; i < m; i++)
        cin >> q[i].first >> q[i].second >> c;

    stack<int> l, r;
    for (int i = 1; i <= n / 2 + n % 2; i++)
        l.push(i);
    r.push(n);
    for (int i = n / 2 + n % 2 + 1; i < n; i++)
        r.push(i);
    vi a;
    while (!l.empty())
    {
        a.push_back(l.top());
        l.pop();
        if (!r.empty())
            a.push_back(r.top()), r.pop();
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
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
