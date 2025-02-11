//
// Created by Zlin on 2025/2/11.
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

string tag = "CHICKEN";

inline void Zlin()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    queue<char> need;
    for (auto it : tag)
        need.push(it);
    unordered_map<char, int> cnt;
    for (auto it : s)
    {
        if (!need.empty() && it == need.front())
            need.pop();
        else
            cnt[it]++;
    }
    if (!need.empty())
    {
        cout << "NO" << endl;
        return;
    }
    multiset<int> ans;
    for (char it = 'A'; it <= 'Z'; it++)
        if (cnt[it])
            ans.insert(cnt[it]);
    while (ans.size() > 1)
    {
        int r = *prev(ans.end());
        ans.erase(prev(ans.end()));
        int l = *ans.begin();
        ans.erase(ans.begin());
        --r, --l;
        if (l)
            ans.insert(l);
        if (r)
            ans.insert(r);
    }
    if (!ans.empty())
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
