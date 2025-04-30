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


int n, ans;
string s;

inline void dfs(int i, string x)
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
        {
            x[j] ^= 1;
            int tag0 = 0, tag1 = 0;
            for (int k = 1; k < n; k++)
            {
                if (x[k] == '1' && x[k - 1] == '0')
                    ++tag0;
                if (x[k] == '0' && x[k - 1] == '1')
                    ++tag1;
            }
            x[j] ^= 1;
            ans += (tag0 == tag1);
        }
        return;
    }
    if (s[i] != '?')
        dfs(i + 1, x + s[i]);
    else
    {
        dfs(i + 1, x + '0');
        dfs(i + 1, x + '1');
    }
}

inline void Zlin()
{
    cin >> n >> s;
    ans = 0;
    dfs(0, "");
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
