//
// Created by Zlin on 2025/3/15.
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

vi nxt;
int ans;

void get(const string& pat)
{
    int m = pat.size();
    nxt.assign(m, 0);
    for (int i = 2, j = 0; i < m; i++)
    {
        while (j > 0 && pat[i] != pat[j + 1])
            j = nxt[j];
        if (pat[i] == pat[j + 1])
            ++j;
        nxt[i] = j;
    }
}

void kmp(const string& txt, const string& pat)
{
    int n = txt.size() - 1, m = pat.size() - 1;
    get(pat);
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j > 0 && (j == m || txt[i] != pat[j + 1]))
            j = nxt[j];
        if (txt[i] == pat[j + 1])
            ++j;
        ans = max(ans, j);
    }
}

inline void Zlin()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& it : a)
        cin >> it, it = ' ' + it;
    ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            string l = a[i], r = a[j];
            if (l.length() < r.length())
                swap(l, r);
            string c;
            for (int k = r.length() - 1; k >= 0; k--)
            {
                c = r[k] + c;
                kmp(l, c);
            }
        }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
