//
// Created by Zlin on 2025/1/21.
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

int n;

struct Node
{
    int val, id;

    bool operator<(const Node& a) const
    {
        if (val != a.val)
            return val < a.val;
        return id < a.id;
    }
};

set<Node> now;

int mx = 0, mm = INT_MAX;
int ans;
vi a;

inline void Zlin()
{
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        Node x;
        cin >> a[i];
        x.val = a[i];
        mx = max(mx, x.val);
        mm = min(mm, x.val);
        x.id = i;
        now.insert(x);
    }
    ans = 2 * (mx - mm);
    int l, r;
    Node x = *now.begin();
    now.erase(now.begin());
    l = x.id, r = x.id;
    mx = max(mx, x.val * 2);
    mm *= 2;
    while (!now.empty())
    {
        ans = min(ans, mx - min(mm, now.begin()->val));
        x = *now.begin();
        now.erase(now.begin());
        mx = max(mx, x.val * 2);
        while (x.id < l - 1)
        {
            --l;
            auto it = now.find({a[l], l});
            now.erase(it);
            mx = max(mx, a[l] * 2);
        }
        while (x.id > r + 1)
        {
            ++r;
            auto it = now.find({a[r], r});
            now.erase(it);
            mx = max(mx, a[r] * 2);
        }
        l = min(l, x.id), r = max(r, x.id);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
