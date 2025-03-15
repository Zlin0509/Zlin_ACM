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

struct node
{
    int x, y;

    bool operator<(const node& b) const
    {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

struct pnn
{
    node a, b;

    bool operator<(const pnn& p) const
    {
        if (p.a.y != a.y)
            return a.y < p.a.y;
        return a.x < p.a.x;
    }
};

inline void Zlin()
{
    int w, h, l;
    cin >> w >> h >> l;
    int n;
    cin >> n;
    vector<pnn> s(n);
    vector<vector<pnn>> lx(l + 2), rx(l + 2);
    for (auto& [a,b] : s)
    {
        int az, bz;
        cin >> a.x >> a.y >> az >> b.x >> b.y >> bz;
        lx[az].push_back({a, b});
        rx[bz + 1].push_back({a, b});
    }
    for (int i = 0; i <= l; i++)
    {
        sort(lx[i].begin(), lx[i].end());
        sort(rx[i].begin(), rx[i].end());
    }
    set<node> need;
    need.insert({w, h});
    for (int i = 0; i <= h; i++)
    {
        for (auto [a,b] : rx[i])
        {
        }
    }
    cout << "Yes" << endl;
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
