#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 10;
int n;

struct Node
{
    int s[2];
    int p;
    int val;
    int cnt;
    int size;
    void init(int p1, int val1)
    {
        p = p1, val = val1;
        cnt = size = 1;
    }
} tr[N];
int root = 0, tot = 0;

inline void pushup(int x) // 更新点x的大小
{
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + tr[x].cnt;
}

inline void rotate(int x) // 旋转x
{
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1];
    tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y;
    tr[y].p = x;
    pushup(x), pushup(y);
}

inline void splay(int x, int k)
{
    while (tr[x].p != k)
    {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)
            (tr[y].s[0] == x) ^ (tr[z].s[0] == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (k == 0)
        root = x;
}

inline void find(int val) // 找到权值等于val的点并把它转为根
{
    int x = root;
    while (tr[x].s[val > tr[x].val] && tr[x].val != val)
        x = tr[x].s[val > tr[x].val];
    splay(x, 0);
}

inline int get_pre(int val) // 求前驱
{
    find(val);
    int x = root;
    if (tr[x].val < val)
        return x;
    x = tr[x].s[0];
    while (tr[x].s[1])
        x = tr[x].s[1];
    return x;
}

inline int get_suc(int val) // 求后继
{
    find(val);
    int x = root;
    if (tr[x].val > val)
        return x;
    x = tr[x].s[1];
    while (tr[x].s[0])
        x = tr[x].s[0];
    return x;
}

inline void insert(int val)
{
    int x = root, p = 0;
    while (x && tr[x].val != val)
        p = x, x = tr[x].s[val > tr[x].val];
    if (x)
        ++tr[x].cnt;
    else
    {
        x = ++tot;
        tr[p].s[val > tr[p].val] = x;
        tr[x].init(p, val);
    }
    splay(x, 0);
}

inline void del(int val)
{
    int pre = get_pre(val);
    int suc = get_suc(val);
    splay(pre, 0);
    splay(suc, pre);
    int del = tr[suc].s[0];
    if (tr[del].cnt > 1)
        --tr[del].cnt, splay(del, 0);
    else
        tr[suc].s[0] = 0, splay(suc, 0);
}
// 因为预处理插入了两个无穷大和无穷小的数，所以排名不需要+1
inline int get_rank(int val) // 查询val的排名
{
    find(val);
    if (tr[root].val < val)//如果val没有出现过，要判断根节点和val的大小关系
        return tr[tr[root].s[0]].size + tr[root].cnt;
    return tr[tr[root].s[0]].size;
}
// 因为插入了无穷大和无穷小，所以传入k时要+1,k为实际情况的k+1
inline int get_val(int k) // 查询排名为k的val
{
    int x = root;
    while (1)
    {
        int y = tr[x].s[0];
        if (tr[x].cnt + tr[y].size < k)
        {
            k -= tr[x].cnt + tr[y].size;
            x = tr[x].s[1];
        }
        else
        {
            if (tr[y].size >= k)
                x = tr[x].s[0];
            else
                break;
        }
    }
    splay(x, 0);
    return tr[x].val;
}

int opt, x;
void Zlin()
{
    cin >> n;
    while (n--)
    {
        cin >> opt >> x;
        if (opt == 1)
            insert(x);
        if (opt == 2)
            del(x);
        if (opt == 3)
            cout << get_rank(x) << '\n';
        if (opt == 4)
            cout << get_val(x + 1) << '\n';
        if (opt == 5)
            cout << tr[get_pre(x)].val << '\n';
        if (opt == 6)
            cout << tr[get_suc(x)].val << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    insert(1e9);
    insert(-1e9);
    Zlin();
    return 0;
}