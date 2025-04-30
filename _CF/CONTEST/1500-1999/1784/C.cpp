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

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    multiset<int> s;
    for (int& it : a)
        cin >> it, s.insert(it);
    vll ans(n);
    ll res = 0;
    int tag = 1;
    multiset<int> need, lost;
    while (!s.empty())
    {
        int z = *s.begin();
        s.erase(s.begin());
        if (z >= tag)
        {
            res += z - tag;
            need.insert(z);
            ++tag;
        }
        else
            lost.insert(z);
    }
    for (int i = n - 1, z; i >= 0; i--)
    {
        ans[i] = res;
        z = a[i];
        if (lost.lower_bound(z) != lost.end())
        {
            int tag = *lost.lower_bound(z);
            res += tag - z;
            need.insert(tag);
            lost.erase(lost.lower_bound(z));
        }
        else res += need.size() - z;
        need.erase(need.find(z));
    }
    for (ll it : ans)
        cout << it << ' ';
    cout << endl;
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
