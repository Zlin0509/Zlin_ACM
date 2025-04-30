//
// Created by Zlin on 2025/1/26.
//

#include "bits/stdc++.h"
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

class FenwickTree
{
private:
    vi t;

public:
    FenwickTree(int n) : t(n + 1, 0)
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

int cal(const vi& a)
{
    int n = a.size();
    FenwickTree ft(n);
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ft.upd(a[i], 1);
        res += ft.qry(a[i] - 1);
    }
    return res;
}

int n, k;

struct Node
{
    int len, m = INT_MAX;
    vi val, idx;

    // 默认小的块排在前面
    bool operator<(const Node& x) const
    {
        return m < x.m;
    }
};

vector<Node> a;
vi sum;

inline void Zlin()
{
    cin >> n >> k;

    a.assign(n, {});
    sum.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].len;
        a[i].val.assign(a[i].len, 0);
        a[i].idx.assign(a[i].len, 0);
        for (int j = 0; j < a[i].len; j++)
        {
            cin >> a[i].val[j];
            a[i].m = min(a[i].m, a[i].val[j]);
        }
    }

    // 统计后缀和
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i].len;

    // 处理每个小块内的逆序
    for (int i = 0; i < n; i++)
    {
        vi now;
        for (int it : a[i].val)
            now.push_back(it);
        sort(now.begin(), now.end());
        for (int j = 0; j < a[i].len; j++)
            a[i].idx[j] = lower_bound(now.begin(), now.end(), a[i].val[j]) - now.begin() + 1;
        k -= cal(a[i].idx);
    }

    if (k < 0)
    {
        cout << "No" << endl;
        return;
    }
    if (k == 0)
    {
        cout << "Yes" << endl;
        for (auto x : a)
            for (auto it : x.val)
                cout << it << ' ';
        return;
    }

    // 存储被移到末尾的数
    stack<int> R;
    // 存储最后那个特殊值
    int tag, val;

    for (int i = 0; i < n - 1; i++)
    {
        while (sum[i + 1] < k && a[i].val.size())
        {
            k -= sum[i + 1];
            R.push(a[i].val.back());
            a[i].val.pop_back();
        }
        if (a[i].val.size())
        {
            for (int j = i + 1; j < n; j++)
            {
                for (auto it : a[j].val)
                {
                    --k;
                    if (!k)
                    {
                        tag = it;
                        break;
                    }
                }
                if (!k)
                    break;
            }
            val = a[i].val.back();
            a[i].val.pop_back();
        }
        if (!k)
            break;
    }
    if (k)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        for (auto it : a[i].val)
        {
            cout << it << ' ';
            if (it == tag)
                cout << val << ' ';
        }
    }
    while (!R.empty())
    {
        cout << R.top() << ' ';
        R.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
