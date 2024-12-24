//
// Created by Zlin on 2024/12/20.
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

inline void Zlin()
{
    int n, x, y;
    cin >> n >> x >> y;
    vi ans(n);
    x--, y--;
    if (x > y) swap(x, y);
    ans[x] = 0;
    auto cal = [&](int z)
    {
        return (z + n) % n;
    };
    for (int i = x + 1; i < y; i++) ans[i] = ans[i - 1] ^ 1;
    for (int i = x - 1; ~i; i--) ans[i] = ans[i + 1] ^ 1;
    for (int i = n - 1; i > y; i--) ans[i] = ans[cal(i + 1)] ^ 1;
    set<int> have;
    have.insert(ans[x]);
    have.insert(ans[cal(y - 1)]);
    have.insert(ans[cal(y + 1)]);
    while (!have.empty() && ans[y] == *have.begin())
    {
        have.erase(have.begin());
        ++ans[y];
    }
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
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
