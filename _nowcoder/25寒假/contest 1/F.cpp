//
// Created by Zlin on 2025/1/21.
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

constexpr int N = 1e5 + 10;

inline void Zlin()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> f(n + 1);
    auto ans = 0ll;
    for (int i = 1; i <= n; i++)
    {
        set<int> st;
        map<int, int> mp;
        mp[0]++;
        f[i - 1] = 0;
        for (int j = i; j <= n; j++)
        {
            st.insert(a[j]);
            if (st.size() > 2)
            {
                i = j;
                st.clear();
                for (; i >= 1; i--)
                {
                    st.insert(a[i]);
                    if (st.size() > 2) break;
                }
                break;
            }
            f[j] = f[j - 1];
            if (a[j] == a[i]) f[j]++;
            else f[j]--;
            ans += mp[f[j]];
            mp[f[j]]++;
            if (j == n) i = n;
        }
    }
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
