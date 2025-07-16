//
// Created by Zlin on 2025/2/6.
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

int n, p, k;
vi a, ans;

int find1(int x)
{
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

/*
    先处理不取mo的一组
    范围为 [x - a[i], p - a[i])
    查找完特判是否存在
    同时处理查找区间是否和自身重复
    如果重复 减去自身的影响

    然后处理要取一个mo的一组(容易证明最多只会取一次mo)
    范围为 [p + x - a[i], 2 * p - a[i])
    计算方式同理
*/
bool check(const int& x)
{
    // res可能超过int 硬控我两小时
    ll res = 0;
    for (int i = 0, k; i < n; i++)
    {
        k = find1(x - a[i]);
        res += n - k;
        if (k <= i)
            --res;
        k = find1(p - a[i]);
        res -= n - k;
        if (k <= i)
            ++res;

        k = find1(p + x - a[i]);
        res += n - k;
        if (k <= i)
            --res;
        k = find1(2 * p - a[i]);
        res -= n - k;
        if (k <= i)
            ++res;
    }
    return res >= k * 2;
}

inline void Zlin()
{
    cin >> n >> p >> k;
    a.assign(n, 0);
    ans.clear();
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] %= p;
    sort(a.begin(), a.end());
    int l = 0, r = p - 1, mid;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    int tag = check(l) ? l + 1 : l;
    for (int i = 0; i < n; i++)
    {
        l = find1(tag - a[i]);
        l = max(l, i + 1);
        r = find1(p - a[i]);
        r = max(r, i + 1);
        for (int j = l; j < r; j++)
            ans.push_back(a[j] + a[i]);

        l = find1(p + tag - a[i]);
        l = max(l, i + 1);
        r = find1(2 * p - a[i]);
        r = max(r, i + 1);
        for (int j = l; j < r; j++)
            ans.push_back(a[j] + a[i] - p);
    }
    while (ans.size() < k)
        ans.push_back(tag - 1);
    sort(ans.begin(), ans.end(), greater<int>());
    for (auto it : ans)
        cout << it << ' ';
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
