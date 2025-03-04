//
// Created by 27682 on 2025/3/4.
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
    int n, x;
    cin >> n >> x;
    vi c(n);
    for (int& it : c)
        cin >> it;
    priority_queue<int> now;
    ll have = 0, need = 0;
    for (int it : c)
    {
        if (need + it <= have)
        {
            now.push(it);
            need += it;
        }
        else if (!now.empty() && now.top() > it)
        {
            need -= now.top();
            now.pop();
            need += it;
            now.push(it);
        }
        have += x;
    }
    cout << now.size() << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}
