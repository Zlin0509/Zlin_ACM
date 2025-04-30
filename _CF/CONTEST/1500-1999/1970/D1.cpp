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

/*
 * 基础信息:
 * 合法性:子节点的最短串的最长后缀=父节点的最长串
 * 节点的子串长度:最长子串=len[i] 最短子串=len[i]-len[fa[i]]
 * 节点的子串数量=len[i]-len[fa[i]]
 * 子串的出现次数=cnt[i]
 */
struct SAM
{
private:
    int tot, np;
    vll fa, len, cnt;
    vector<unordered_map<char, int>> ch;

    void extend(char c)
    {
        int p = np;
        np = ++tot;
        len[np] = len[p] + 1;
        cnt[np] = 1;
        // 从链接边向前遍历,更新旧点的链接边
        while (p && !ch[p][c])
        {
            ch[p][c] = np;
            p = fa[p];
        }
        // 更新链接边
        if (!p)
            fa[np] = 1; // 指向根节点,是新字符,直接创建
        else
        {
            int q = ch[p][c];
            if (len[q] == len[p] + 1)
                fa[np] = q; // 相邻,合法,直接加边
            else
            {
                // 不相邻,不合法,要求新建一个链接点,然后把p点之前的所有点的路径更新
                int nq = ++tot;
                len[nq] = len[p] + 1;
                fa[nq] = fa[q];
                fa[q] = nq;
                fa[np] = nq;
                while (p && ch[p][c])
                {
                    ch[p][c] = nq;
                    p = fa[p];
                }
                // 将原先的转移边复制到nq上
                ch[nq] = ch[q];
            }
        }
    }

public:
    // n不该是题目给的n,要足够大保证链接点够,建议为 n*2 大小
    void init(string s)
    {
        int n = s.length() * 2;
        tot = np = 1;
        fa.assign(n + 1, 0);
        len.assign(n + 1, 0);
        cnt.assign(n + 1, 0);
        // ch 存放链接边信息
        ch.assign(n + 1, unordered_map<char, int>());

        for (auto it : s)
            extend(it);
    }

    ll get_count()
    {
        ll res = 0;
        for (int i = 1; i <= tot; i++)
            res += len[i] - len[fa[i]];
        return res;
    }
} sam;

inline void Zlin()
{
    int n, q, x;
    cin >> n;
    string x1 = "OXO", x2 = "OOOXXXX", x3 = "OOOOOOOOXXXXXXXXOX";
    if (n == 1)
    {
        cout << x1 << endl;
        cout.flush();
        cin >> q;
        while (q--)
        {
            cin >> x;
            cout << 1 << ' ' << 1 << endl;
            cout.flush();
        }
    }
    else if (n == 2)
    {
        cout << x1 << endl << x2 << endl;
        cout.flush();
        cin >> q;
        sam.init(x1 + x1);
        int t11 = sam.get_count();
        sam.init(x1 + x2);
        int t12 = sam.get_count();
        sam.init(x2 + x1);
        int t21 = sam.get_count();
        sam.init(x2 + x2);
        int t22 = sam.get_count();
        while (q--)
        {
            cin >> x;
            if (x == t11) cout << 1 << ' ' << 1 << endl;
            else if (x == t12) cout << 1 << ' ' << 2 << endl;
            else if (x == t21) cout << 2 << ' ' << 1 << endl;
            else if (x == t22) cout << 2 << ' ' << 2 << endl;
            cout.flush();
            cout.flush();
        }
    }
    else
    {
        cout << x1 << endl << x2 << endl << x3 << endl;
        cout.flush();
        cin >> q;
        sam.init(x1 + x1);
        int t11 = sam.get_count();
        sam.init(x1 + x2);
        int t12 = sam.get_count();
        sam.init(x1 + x3);
        int t13 = sam.get_count();
        sam.init(x2 + x1);
        int t21 = sam.get_count();
        sam.init(x2 + x2);
        int t22 = sam.get_count();
        sam.init(x2 + x3);
        int t23 = sam.get_count();
        sam.init(x3 + x1);
        int t31 = sam.get_count();
        sam.init(x3 + x2);
        int t32 = sam.get_count();
        sam.init(x3 + x3);
        int t33 = sam.get_count();
        while (q--)
        {
            cin >> x;
            if (x == t11) cout << 1 << ' ' << 1 << endl;
            else if (x == t12) cout << 1 << ' ' << 2 << endl;
            else if (x == t13) cout << 1 << ' ' << 3 << endl;
            else if (x == t21) cout << 2 << ' ' << 1 << endl;
            else if (x == t22) cout << 2 << ' ' << 2 << endl;
            else if (x == t23) cout << 2 << ' ' << 3 << endl;
            else if (x == t31) cout << 3 << ' ' << 1 << endl;
            else if (x == t32) cout << 3 << ' ' << 2 << endl;
            else if (x == t33) cout << 3 << ' ' << 3 << endl;
            cout.flush();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}
