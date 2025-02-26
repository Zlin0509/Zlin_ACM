//
// Created by 27682 on 2025/2/26.
//
#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin()
{
    int n;
    cin >> n;
    struct node
    {
        int val, id;

        bool operator<(const node& b)
        {
            if (val != b.val)
                return val > b.val;
            return id < b.id;
        }
    };
    vector<node> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].val, a[i].id = i;
    sort(a.begin(), a.end());
    int l = 1, r = n, mid;
    auto check = [&](int x)
    {
        vector<node> res;
        for (int i = 0; i < x; i++)
            res.push_back(a[i]);
        sort(res.begin(), res.end(), [](node x, node y)
        {
            return x.id < y.id;
        });
        set<int> now;
        vi mm(x);
        mm[0] = res[0].val;
        for (int i = 1; i < x; i++)
            mm[i] = min(mm[i - 1], res[i].val);
        int tag = -1;
        now.insert(res[x - 1].val);
        for (int i = x - 2; i >= 0; i--)
        {
            while (*now.begin() == tag + 1)
                ++tag, now.erase(now.begin());
            if (tag + 1 > mm[i])
                return false;
            now.insert(res[i].val);
        }
        return true;
    };
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}
