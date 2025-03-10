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

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n), r(n), l(n);
    for (auto& it : a)
        cin >> it;
    cout << "YES\n1 1" << endl;
    r[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (!a[i])
        {
            cout << i + 1 << " 1\n", r[i] = 1, l[i] = i;
            continue;
        }
        int x = a[i] - i;
        if (x >= 0)cout << i + 1 << ' ' << (r[i] = x + 1) << endl;
        else cout << i + 1 << ' ' << (r[i] = r[l[i] = i - a[i]]) << endl;
    }
    for (int i : l)cout << i + 1 << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}
