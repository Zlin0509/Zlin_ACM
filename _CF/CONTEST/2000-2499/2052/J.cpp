//
// Created by Zlin on 2025/1/25.
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

constexpr int N = 2e5 + 10;

int n, m, q;
queue<int> l;
vll t;

struct Node
{
    ll a, d;

    bool operator<(const Node& b) const
    {
        if (d != b.d)
            return d > b.d;
        return a > b.a;
    }
};

vector<Node> works;

// 存储完成n个作业需要占用的时间的左右边界
set<pll> blocks;
// 存储对于m个剧集可以看完的最早时间，对于q次查询在have中二分查找
vll have;

inline void read()
{
    cin >> n >> m >> q;
    works.assign(n, {});
    t.assign(q, 0);
    for (int i = 0; i < n; i++)
        cin >> works[i].a;
    for (int i = 0; i < n; i++)
        cin >> works[i].d;
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        l.push(x);
    }
    for (int i = 0; i < q; i++)
        cin >> t[i];
}

inline void Zlin()
{
    read();

    // 处理能完成这n个作业的最晚时间区间
    blocks.clear();
    sort(works.begin(), works.end());
    ll L, R;
    L = works[0].d - works[0].a, R = works[0].d;
    for (int i = 1; i < n; i++)
    {
        if (L > works[i].d)
        {
            blocks.insert({L, R});
            L = works[i].d - works[i].a, R = works[i].d;
        }
        else L -= works[i].a;
    }
    blocks.insert({L, R});

    // 计算每个剧集最早看完的时间
    have.clear();
    ll tag = 0;
    while (!l.empty())
    {
        int x = l.front();
        l.pop();
        while (!blocks.empty() && tag + x > blocks.begin()->first)
        {
            L = blocks.begin()->first;
            R = blocks.begin()->second;
            blocks.erase(blocks.begin());
            tag = R - L + tag;
        }
        tag += x;
        have.push_back(tag);
    }

    // for (int it : have)
    //     cout << it << ' ';
    // cout << endl;

    for (int i = 0; i < q; i++)
        cout << upper_bound(have.begin(), have.end(), t[i]) - have.begin() << ' ';
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
