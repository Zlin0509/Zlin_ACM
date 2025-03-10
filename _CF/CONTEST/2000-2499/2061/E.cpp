//
// Created by Zlin on 2025/1/28.
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

constexpr int INF = (1ll << 31) - 1;
int n, m, k;
ll ans;
vi a, b, c;

vi now;

inline void Zlin()
{
    cin >> n >> m >> k;
    ans = 0;
    now.clear();
    a.assign(n, 0);
    b.assign(m, 0);
    c.assign(1 << m, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // 很明显的状压 状压预处理这m个数能&出来的所有值
    for (int i = 0, k; i < 1 << m; i++)
    {
        c[i] = INF;
        k = 0;
        while (1 << k <= i)
        {
            if (1 << k & i)
                c[i] &= b[k];
            ++k;
        }
    }

#if
    对于每个a[i]去进行& 不难发现每个每次&出的新东西<=等于原来的东西
    对于每次&操作 我们都取最终结果最小的 所以对于每个a[i]进行的实际每个&操作
    对答案的贡献为第j次&的值 减去 第j-1次&的值(是一个负数,每个值都仅代表一次操作)
    所以答案就是这n*m个贡献中最小的k个
#endif
    for (int i = 0; i < n; i++)
    {
        vi val(m + 1, INF);
        for (int j = 0; j < 1 << m; j++)
            val[__builtin_popcount(j)] = min(val[__builtin_popcount(j)], a[i] & c[j]);
        for (int j = 1; j <= m; j++)
            now.push_back(val[j] - val[j - 1]);
    }
    sort(now.begin(), now.end());
    for (int i = 0; i < k; i++)
        ans += now[i];
    cout << ans << endl;
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
