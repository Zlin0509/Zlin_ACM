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
    int n;
    cin >> n;
    ll amx = 0;
    int cntMax = 0;
    ll same = 0;
    ll mm = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a > amx)
        {
            amx = a;
            cntMax = 1;
            same = b;
        }
        else if (a == amx)
        {
            cntMax++;
            same = max(same, b);
        }
        else
        {
            mm = max(mm, a + b);
        }
    }
    ll ans = amx; // 候选一
    ans = max(ans, mm); // 候选二
    if (cntMax >= 2)
    {
        ans = max(ans, amx + same); // 候选三：只有当最大基础offer的公司不止一家时才能谈薪
    }
    cout << ans << "\n";
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
