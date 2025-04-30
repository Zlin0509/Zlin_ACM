//
// Created by Zlin on 2025/2/8.
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

class Ftree
{
private:
    vi t;

public:
    Ftree(int n) : t(n + 1, 0)
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

    int qry1(int l, int r)
    {
        return qry(r) - qry(l - 1);
    }
};

int n;
string s;

inline void Zlin()
{
    cin >> n;
    cin >> s;
    Ftree t0(n), t1(n);
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
            t0.upd(i, 1);
        else
            t1.upd(i, 1);
    }
    int len = 0, ans = 1;
    for (int i = 2; i <= n; i++)
    {
        vi now;
        int tag = 0;
        for (int j = 1, l, r; j <= n; j += i)
        {
            l = j, r = min(n, j + i - 1);

            // 如果这一段是干净的直接跳过
            if (!t0.qry1(l, r) || !t1.qry1(l, r))
                continue;

            if (!tag) // 如果前面没有1残留
            {
                now.push_back(tag);
                tag = 1;
            }
            else // 如果有残留 直接留下 重新从0开始
            {
                now.push_back(tag);
                tag = 0;
            }
        }
        now.push_back(tag);
        ans ^= now.size();
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
