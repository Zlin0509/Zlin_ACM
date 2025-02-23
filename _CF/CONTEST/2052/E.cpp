//
// Created by Zlin on 2025/2/22.
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

struct BigInt
{
    vi now; // 按位存储 低位在前 高位在后
    bool tag = false; // 判断是否是负数

    void init(string s)
    {
        int l = 0, r = s.size() - 1;
        if (s[0] == '-')
            tag = true, l = 1;
        while (r >= l)
            now.push_back(s[r--] - '0');
        trim(now);
    }

    // 清除前导零
    void trim(vi& a)
    {
        while (a.back() == 0)
            a.pop_back();
        if (a.empty())
            a.push_back(0), tag = false;
    }

    // 比较绝对值大小
    bool checkabs(const BigInt& a, const BigInt& b)
    {
        if (a.now.size() != b.now.size())
            return a.now.size() > b.now.size();
        for (int i = a.now.size() - 1; i >= 0; i--)
            if (a.now[i] != b.now[i])
                return a.now[i] > b.now[i];
        return true;
    }

    // 加法
    BigInt add(const BigInt& a, const BigInt& b)
    {
        BigInt res;
        res.tag = a.tag;
        int now = 0;
        for (int i = 0; i < max(a.now.size(), b.now.size()) || now; i++)
        {
            int sum = now;
            if (i < a.now.size())
                sum += a.now[i];
            if (i < b.now.size())
                sum += b.now[i];
            res.now.push_back(sum % 10);
            now = sum / 10;
        }
        trim(res.now);
        return res;
    }

    // 减法
    BigInt sub(const BigInt& a, const BigInt& b)
    {
        BigInt res;

    }
};

inline void Zlin()
{
    string s;
    cin >> s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
