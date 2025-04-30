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

ll a[1000010][3];

inline void Zlin()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    unordered_map<ll, int> cnt;
    set<ll> have;
    auto cal = [&](ll* z)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int q = 0; q < 3; q++)
                {
                    if (i == j || i == q || j == q)
                        continue;
                    ll a = z[i], b = z[j], c = z[q];
                    if (c < b || (c - b) % a)
                        continue;
                    ll x = (c - b) / a;
                    have.insert(x);
                    cnt[x]++;
                }
    };
    for (int i = 0; i < n; i++)
        cal(a[i]);
    int tag = 0, ans = -1;
    for (auto it : have)
        if (cnt[it] > tag)
        {
            tag = cnt[it];
            ans = it;
        }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    exit(0);
}
