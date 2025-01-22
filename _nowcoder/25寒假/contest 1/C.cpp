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

int n;
vector<vi> a;

struct Node
{
    int x, y;

    bool operator<(const Node& b) const
    {
        if (x != b.x)
            return x < b.x;
        return y < b.y;
    }
};

set<Node> have;

vector<pair<Node, Node>> ans;

inline void Zlin()
{
    cin >> n;
    a.assign(n + 2, vi(n + 2, 0));
    char c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            a[i][j] = c - '0';
            if (c == '1')
                have.insert({i, j});
        }
    for (int x = 1; x <= n / 2; x++)
    {
        for (int y = 1; y <= n / 2; y++)
        {
            Node u = *have.begin();
            have.erase(have.begin());
            a[u.x][u.y] = 0;
            while (u.y < y)
            {
                if (a[u.x][u.y + 1] == 1)
                {
                    have.erase(have.find({u.x, u.y + 1}));
                    have.insert(u);
                    a[u.x][u.y + 1] = 0;
                    a[u.x][u.y] = 1;
                }
                ans.push_back({u, {u.x, u.y + 1}});
                u.y++;
            }
            while (u.x < x)
            {
                if (a[u.x + 1][u.y] == 1)
                {
                    have.erase(have.find({u.x + 1, u.y}));
                    have.insert(u);
                    a[u.x + 1][u.y] = 0;
                    a[u.x][u.y] = 1;
                }
                ans.push_back({u, {u.x + 1, u.y}});
                u.x++;
            }
            while (u.x > x)
            {
                if (a[u.x - 1][u.y] == 1)
                {
                    have.erase(have.find({u.x - 1, u.y}));
                    have.insert(u);
                    a[u.x - 1][u.y] = 0;
                    a[u.x][u.y] = 1;
                }
                ans.push_back({u, {u.x - 1, u.y}});
                u.x--;
            }
            while (u.y > y)
            {
                if (a[u.x][u.y - 1] == 1)
                {
                    have.erase(have.find({u.x, u.y - 1}));
                    have.insert(u);
                    a[u.x][u.y - 1] = 0;
                    a[u.x][u.y] = 1;
                }
                ans.push_back({u, {u.x, u.y - 1}});
                u.y--;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it.first.x << " " << it.first.y << " " << it.second.x << " " << it.second.y << endl;
    have.clear();
    ans.clear();
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
