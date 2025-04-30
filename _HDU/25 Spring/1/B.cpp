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

inline void Zlin()
{
    int n;
    cin >> n;
    vector a(n, vll(3, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    auto check = [](ll c, vll a)
    {
 int cnt =0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    for (int q = 0; q < 3; q++)
                        if (i != q && j != q)
                        {
                            ll x = a[i], y = a[j], z = a[q];
                            if (x * c + y == z)
                              cnt++;
                        }
        return cnt==1;
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != j)
                for (int q = 0; q < 3; q++)
                    if (i != q && j != q)
                    {
                        ll x = a[0][i], y = a[0][j], z = a[0][q];
                        if ((z - y) % x || z < y)
                            continue;
                        ll ans = (z - y) / x;
                        bool tt = true;
                        for (auto& it : a)
                            if (!check(ans, it))
                            {
                                tt = false;
                                break;
                            }
                        if (tt)
                        {
                            cout << ans << endl;
                            return;
                        }
                    }
}

int main()
{
    int size(256 << 20); // 256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size) + size));
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    exit(0);
}