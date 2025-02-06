//
// Created by Zlin on 2025/2/3.
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

class FTree
{
private:
    vi t;

public:
    FTree(int n) : t(n + 1, 0)
    {
    }

    void upd(int i, int v)
    {
        while (i < t.size())
        {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qryRange(int l, int r)
    {
        return qry(r) - qry(l - 1);
    }
};

struct Node
{
    int x, y;

    bool operator<(const Node& b) const
    {
        if (x != b.x)
            return x < b.x;
        return y < b.y;
    }
};

vector<Node> a;
vi dy;

int n, ans;
Node u;

inline int check(int dif, FTree& lt, FTree& rt)
{
    int x1 = lt.qryRange(1, dif - 1);
    int x2 = lt.qryRange(dif, dy.size());
    int x3 = rt.qryRange(1, dif - 1);
    int x4 = rt.qryRange(dif, dy.size());
    return min({x1, x2, x3, x4});
}

inline void work(FTree& lt, FTree& rt)
{
    ans = 0;
    u = {0, 0};

    int l, r, mid;
    int now = 0, tag;
    // 对于x排序后遍历查询
    while (now < n)
    {
        // 二分查找对应的y
        l = 1, r = dy.size();
        while (l < r)
        {
            mid = l + r + 1 >> 1;
            int xa = lt.qryRange(1, mid - 1);
            int xb = rt.qryRange(1, mid - 1);
            int xx = check(mid, lt, rt);
            // 最大值可能是中间某一个过程
            if (xx > ans)
            {
                ans = xx;
                u = {a[now].x, dy[mid - 1]};
            }
            // 如果左半部分小，指针右移，反之左移
            if (xa == xx || xb == xx)
                l = mid;
            else
                r = mid - 1;
        }
        if (check(l, lt, rt) > ans)
        {
            ans = check(l, lt, rt);
            u = {a[now].x, dy[l - 1]};
        }

        // 更新操作
        tag = a[now].x;
        while (now < n && a[now].x == tag)
        {
            int k = lower_bound(dy.begin(), dy.end(), a[now].y) - dy.begin() + 1;
            rt.upd(k, -1);
            lt.upd(k, 1);
            ++now;
        }
    }
}

inline void Zlin()
{
    cin >> n;
    dy.clear();
    a.assign(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        dy.push_back(a[i].y);
    }

    sort(a.begin(), a.end());

    sort(dy.begin(), dy.end());
    dy.erase(unique(dy.begin(), dy.end()), dy.end());
    FTree lt(dy.size()), rt(dy.size());

    for (Node& it : a)
        rt.upd(lower_bound(dy.begin(), dy.end(), it.y) - dy.begin() + 1, 1);

    work(lt, rt);
    cout << ans << endl;
    cout << u.x << ' ' << u.y << endl;
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
