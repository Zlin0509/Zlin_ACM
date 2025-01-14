//
// Created by Zlin on 2025/1/13.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 200;
constexpr db EPS = 1E-8;

inline void Zlin()
{
    db a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    db beg = 0, end = v, mid;
    auto check = [&](db x)
    {
        db x1, x2;
        x1 = (x * x) / (2.0 * a);
        if (x < w) x2 = 0.0;
        else x2 = (x * x - w * w) / (2.0 * a);
        return x1 + x2 < d;
    };
    for (int i = 0; i < N; i++)
    {
        mid = (beg + end) / 2.0;
        if (check(mid)) beg = mid;
        else end = mid;
    }
    // cout << beg << ' ';
    db ans = 0, x = d - (beg * beg) / (2.0 * a);
    ans += beg / a;
    if (beg > w) ans += (beg - w) / a, x -= (beg * beg - w * w) / (2.0 * a);
    if (x > 0.0) ans += x / beg;
    auto cal = [&](db speed, db have)
    {
        db res = 0;
        db x = (v * v - speed * speed) / (2.0 * a);
        if (x > have)
        {
            db p = 0, q = have / speed;
            for (int i = 0; i < N; i++)
            {
                mid = (p + q) / 2.0;
                x = speed * mid + a * mid * mid / 2.0;
                if (x > have) q = mid;
                else p = mid;
            }
            res += p;
        }
        else
        {
            have -= x;
            res += have / v;
            res += (v - speed) / a;
        }
        return res;
    };
    ans += cal(min(beg, w), l - d);
    printf("%.12lf", ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
