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

inline string get_new(const string& s)
{
    string res = "#";
    for (auto it : s)
    {
        res += it;
        res += '#';
    }
    return res;
}

// res代表以i为中心的回文串的长度
inline vi work(const string& x)
{
    string s = get_new(x);
    int n = s.length();
    vi res(n);
    // 当前最长回文中间点所在位置
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 2 * c - i;
        if (i < c + res[c])res[i] = min(res[l], c + res[c] - i);
        while (i - res[i] - 1 >= 0 && i + res[i] + 1 < n && s[i - res[i] - 1] == s[i + res[i] + 1]) ++res[i];
        if (i + res[i] > c + res[c]) c = i;
    }
    return res;
}

// 判断是否为回文串,l r为未修改前字符串的坐标
bool ch(int l, int r, vi& p)
{
    int ll = l * 2 + 1, rr = r * 2 + 1;
    int mid = ll + rr >> 1;
    return mid + p[mid] - 1 >= rr;
}

inline void Zlin()
{
    string s;
    cin >> s;
    bool check = true;
    for (auto it : s)
        if (it != s[0])
        {
            check = false;
            break;
        }
    if (check)
    {
        cout << "NO" << endl;
        return;
    }
    vi res = work(s);
    if (!ch(0, s.length() - 1, res))
    {
        cout << "YES\n1\n";
        cout << s << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!ch(0, i, res) && !ch(i + 1, s.length() - 1, res))
        {
            cout << "YES" << endl;
            cout << 2 << endl;
            for (int j = 0; j < s.length(); j++)
            {
                cout << s[j];
                if (j == i)
                    cout << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
