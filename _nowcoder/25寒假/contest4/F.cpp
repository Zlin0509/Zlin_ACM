//
// Created by Zlin on 2025/2/6.
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

int n, p, k;
vi a, ans;

int find1(int x)
{
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

/*
    先处理不取mo的一组
    范围为 [x - a[i], p - a[i])
    查找完特判是否存在
    同时处理查找区间是否和自身重复
    如果重复 减去自身的影响

    然后处理要取一个mo的一组(容易证明最多只会取一次mo)
    范围为 [p + x - a[i], 2 * p - a[i])
    计算方式同理
*/
bool check(const int& x)
{
    int res = 0;
    for (int i = 0, k; i < n; i++)
    {
        k = find1(x - a[i]);
        res += n - k;
        if (k <= i)
            --res;
        k = find1(p - a[i]);
        res -= n - k;
        if (k <= i)
            ++res;

        k = find1(p + x - a[i]);
        res += n - k;
        if (k <= i)
            --res;
        k = find1(2 * p - a[i]);
        res -= n - k;
        if (k <= i)
            ++res;
    }
    return res >= k * 2;
}

inline void Zlin()
{
int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= p;
    }

    ranges::sort(a);
    multiset<int> st;

    // 预填充 k 个 -1
    for (int i = 1; i <= k; i++) {
        st.insert(-1);
    }

    vector<int> r(n + 1);
    for (int i = n; i >= 1; i--) {
        r[i] = ranges::lower_bound(a, p - a[i]) - a.begin();
        if (r[i] > i) r[i] = i;

        for (int j = i - 1; j >= 1; j--) {
            int t = (a[i] + a[j]) % p;
            if (t <= *st.begin()) {
                if (j >= r[i])
                    j = r[i];
                else
                    break;
            }
            st.insert(t);
            st.erase(st.begin());
        }
    }

    for (auto &i : st | views::reverse) {
        cout << i << " ";
    }
    cout << endl;
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
