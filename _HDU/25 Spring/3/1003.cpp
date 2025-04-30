//
// Created by 27682 on 2025/3/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vll x(m);
    vi val(n);
    vector xx(n, vi(m + 1, 0));
    for (ll& it : x)
        cin >> it;
    vector now(m, vector<pii>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, tag; j < m; j++)
        {
            cin >> tag;
            now[j].push_back({tag, i});
        }
        for (int j = 0; j < m; j++)
            cin >> xx[i][j];
    }
    for (int j = 0; j < m; j++)
        sort(now[j].begin(), now[j].end(), greater<pii>());
    int cnt = 0;
    vi have;
    for (int i = 0, id; i < m; i++)
    {
        while (!now[i].empty() && x[i] >= now[i].back().first)
        {
            id = now[i].back().second;
            now[i].pop_back();
            ++val[id];
            if (val[id] == m) have.push_back(id);
        }
    }
    while (!have.empty())
    {
        int i = have.back();
        have.pop_back();
        for (int j = 0, id; j < m; j++)
        {
            x[j] += xx[i][j];
            while (!now[j].empty() && x[j] >= now[j].back().first)
            {
                id = now[j].back().second;
                now[j].pop_back();
                ++val[id];
                if (val[id] == m) have.push_back(id);
            }
        }
        ++cnt;
    }
    cout << (cnt == n ? "YES" : "NO") << endl;
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
